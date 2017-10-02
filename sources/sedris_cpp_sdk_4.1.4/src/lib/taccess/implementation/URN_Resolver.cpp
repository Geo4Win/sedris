/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */
//
// - STF spec. 4.1

/*
 *                             NOTICE
 * 
 * This software is provided openly and freely for use in representing and
 * interchanging environmental data & databases.
 * 
 * This software was developed for use by the United States Government with
 * unlimited rights.  The software was developed under contract
 * DASG60-02-D-0006 TO-193 by Science Applications International Corporation.
 * The software is unclassified and is deemed as Distribution A, approved
 * for Public Release.
 * 
 * Use by others is permitted only upon the ACCEPTANCE OF THE TERMS AND
 * CONDITIONS, AS STIPULATED UNDER THE FOLLOWING PROVISIONS:
 * 
 *    1. Recipient may make unlimited copies of this software and give
 *       copies to other persons or entities as long as the copies contain
 *       this NOTICE, and as long as the same copyright notices that
 *       appear on, or in, this software remain.
 * 
 *    2. Trademarks. All trademarks belong to their respective trademark
 *       holders.  Third-Party applications/software/information are
 *       copyrighted by their respective owners.
 * 
 *    3. Recipient agrees to forfeit all intellectual property and
 *       ownership rights for any version created from the modification
 *       or adaptation of this software, including versions created from
 *       the translation and/or reverse engineering of the software design.
 * 
 *    4. Transfer.  Recipient may not sell, rent, lease, or sublicense
 *       this software.  Recipient may, however enable another person
 *       or entity the rights to use this software, provided that this
 *       AGREEMENT and NOTICE is furnished along with the software and
 *       /or software system utilizing this software.
 * 
 *       All revisions, modifications, created by the Recipient, to this
 *       software and/or related technical data shall be forwarded by the
 *       Recipient to the Government at the following address:
 * 
 *         SMDC
 *         Attention SEDRIS (TO193) TPOC
 *         P.O. Box 1500
 *         Huntsville, AL  35807-3801
 * 
 *         or via electronic mail to:  se-mgmt@sedris.org
 * 
 *    5. No Warranty. This software is being delivered to you AS IS
 *       and there is no warranty, EXPRESS or IMPLIED, as to its use
 *       or performance.
 * 
 *       The RECIPIENT ASSUMES ALL RISKS, KNOWN AND UNKNOWN, OF USING
 *       THIS SOFTWARE.  The DEVELOPER EXPRESSLY DISCLAIMS, and the
 *       RECIPIENT WAIVES, ANY and ALL PERFORMANCE OR RESULTS YOU MAY
 *       OBTAIN BY USING THIS SOFTWARE OR DOCUMENTATION.  THERE IS
 *       NO WARRANTY, EXPRESS OR, IMPLIED, AS TO NON-INFRINGEMENT OF
 *       THIRD PARTY RIGHTS, MERCHANTABILITY, OR FITNESS FOR ANY
 *       PARTICULAR PURPOSE.  IN NO EVENT WILL THE DEVELOPER, THE
 *       UNITED STATES GOVERNMENT OR ANYONE ELSE ASSOCIATED WITH THE
 *       DEVELOPMENT OF THIS SOFTWARE BE HELD LIABLE FOR ANY CONSEQUENTIAL,
 *       INCIDENTAL OR SPECIAL DAMAGES, INCLUDING ANY LOST PROFITS
 *       OR LOST SAVINGS WHATSOEVER.
 */

/** @file URN_Resolver.cpp
@author Gregory A. Hull, Marcus A . Martin (SAIC)
@author Warren Macchi (Accent Geographic)
@brief Implementation of UrnResolver and FileUtils.
*/

#if defined(_WIN32) || defined(WIN32)
#pragma warning(disable: 4786)
#endif

#include "URN_Resolver.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#if defined(_WIN32) || defined(WIN32)
#include <direct.h> // for getcwd
#else
#include <unistd.h> // for getcwd
#include <ctype.h>
#include <limits.h>
#endif
#include <sys/stat.h>
#include <vector>

#ifndef MAX_PATH
#define MAX_PATH 512
#endif

#define IS_SLASH(_c) ((_c) == FileUtils::SystemSlash || (_c) == FileUtils::OtherSlash)

const char FileUtils::WindowsSlash = '\\';
const char FileUtils::WindowsEnvSeparator = ';';
const char FileUtils::UnixSlash = '/';
const char FileUtils::UnixEnvSeparator = ':';

#if defined(_WIN32) || defined(WIN32)
const char FileUtils::SystemSlash = FileUtils::WindowsSlash;
const char FileUtils::SystemEnvSeparator = FileUtils::WindowsEnvSeparator;
const char FileUtils::OtherSlash = FileUtils::UnixSlash;
const char FileUtils::OtherEnvSeparator = FileUtils::UnixEnvSeparator;
#else
const char FileUtils::SystemSlash = FileUtils::UnixSlash;
const char FileUtils::SystemEnvSeparator = FileUtils::UnixEnvSeparator;
const char FileUtils::OtherSlash = FileUtils::WindowsSlash;
const char FileUtils::OtherEnvSeparator = FileUtils::WindowsEnvSeparator;
#endif

using namespace std;


static int s_lineNo = 0; // URN resolver file parsing Line #
static string s_resolverFile;


/// Trims the front space characters
static std::string trimFront( const std::string &str )
{
    std::string::size_type i = 0;

    while (i < str.length() && isspace(str[i]))
        i++;

    return str.substr(i);
}


/** If the path contains "\\some_string\..." then it returns the index of
    the single "\" (any slash type will work), otherwise returns 0.
*/
static int findEndOfNetPath( const std::string &full_path )
{
    std::string::size_type i = 0;

    // skip space
    while (i < full_path.length() && isspace(full_path[i]))
        i++;

    if (full_path.length() < (i+3))
        return 0;

    if (IS_SLASH(full_path[i]) && IS_SLASH(full_path[i+1]))
    {
        i += 2;
        // skip till next slash
        while (i < full_path.length() && !IS_SLASH(full_path[i]))
            i++;

        if (i < full_path.length())
            return i;
    }

    return 0;
}


std::string FileUtils::GetPathOnly( const std::string &full_path, bool with_slash )
{
    string path(trimFront(full_path));
    int at = path.find_last_of(SystemSlash);

    if (string::npos == at)
        at = path.find_last_of(OtherSlash);

    if (string::npos != at)
        return path.substr(0, at + (with_slash? 1 : 0));
    else
        return "";
}


std::string FileUtils::GetFileOnly( const std::string &full_path )
{
    std::string::size_type at = full_path.find_last_of(SystemSlash);

    if (string::npos == at)
        at = full_path.find_last_of(OtherSlash);

    if (string::npos != at && full_path.length() > (at+1))
        return full_path.substr(at+1);
    else
        return full_path;
}


std::string FileUtils::GetFileOnlyNoExt( const std::string &full_path )
{
    string file_only(GetFileOnly(full_path));
    int at = file_only.find_last_of('.');

    if (string::npos != at && at > 0)
        return file_only.substr(0, at);
    else
        return file_only;
}


std::string FileUtils::GetFileExt( const std::string &full_path )
{
    std::string::size_type at = full_path.find_last_of('.');

    if (string::npos != at && full_path.length() > (at+1))
        return full_path.substr(at+1);
    else
        return "";
}


std::string FileUtils::GetCurrDir( bool with_slash )
{
    char dir[MAX_PATH] = "";

    if (getcwd(dir, MAX_PATH) == NULL)
        fprintf(stderr, "Error - FileUtils::GetCurrDir() failed getcwd()\n");

    string path(dir);

    if (!path.empty() && with_slash && path[path.length() - 1] != SystemSlash)
        path += SystemSlash;

    return path;
}


bool FileUtils::SetCurrDir( const std::string &path )
{
    return chdir(trimFront(path).c_str()) != -1;
}


std::string FileUtils::GetAbsolutePath( const std::string &file_path )
{
    string path(PurgeFileProtocol(file_path));

    if (path.empty())
        return path;

    // Note that in Unix the calls fail with ENOENT (No such file or dir)
    // if the file/path does not exist. This is different from Windows.
    // So if the file doesn't exist, then we temporarily create it.
    struct stat file_stat;
    FILE *tmp_f = NULL;
    string abs_path;

    if (stat(path.c_str(), &file_stat) == -1)
    {
        tmp_f = fopen(path.c_str(), "wb");
        if (!tmp_f)
            return path;
    }

#if defined(_WIN32) || defined(WIN32)
    char *ret = _fullpath(NULL, path.c_str(), 0);
    if (ret)
    {
        abs_path = ret;
        free(ret);
    }
#elif defined(canonicalize_file_name)
    char *ret = canonicalize_file_name(path.c_str());
    if (ret)
    {
        abs_path = ret;
        free(ret);
    }
#else
    char buff[PATH_MAX];
    char *ret = realpath(path.c_str(), buff);
    if (ret)
        abs_path = ret;
#endif

    if (tmp_f)
    {
        fclose(tmp_f);
        unlink(path.c_str());
    }

    if (abs_path.empty())
        return path;
    else
        return abs_path;
}


std::string FileUtils::CombinePaths
(
    const std::string &first_part,
    const std::string &second_part,
    char slash
)
{
    if (!slash)
        slash = SystemSlash;

    if (first_part.empty())
        return ConvertSlashes(second_part, slash);
    else if (second_part.empty())
        return ConvertSlashes(first_part, slash);

    string ret(first_part);

    ret += slash;
    ret += second_part;

    return ConvertSlashes(ret, slash);
}


std::string FileUtils::ConvertSlashes
(
    const std::string &full_path,
    char slash
)
{
    if (!slash)
        slash = SystemSlash;

    string path(trimFront(full_path));

    if (path.empty())
        return path;

    string conv_path;

    conv_path.reserve(path.length());

    int net_at = findEndOfNetPath(path); // Check for Windows network path
    bool last_was_slash = false;

    for (std::string::size_type i = 0; i < path.length(); i++)
    {
        char c = path[i];

        if (IS_SLASH(c))
        {
            if ((int)i < net_at || !last_was_slash)
                conv_path += slash;

            last_was_slash = true;
        }
        else
        {
            conv_path += c;
            last_was_slash = false;
        }
    }

    return conv_path;
}


std::string FileUtils::PurgeFileProtocol( const std::string &url )
{
    string file_proto1(URL_FILE_PROTOCOL_1);
    string file_proto2(URL_FILE_PROTOCOL_2);
    string full_path(trimFront(url));
    string file_name;

    if (full_path.find(file_proto1) == 0 || full_path.find(file_proto2) == 0)
    {
        file_name = full_path;

        if (file_name.find(file_proto1) != string::npos)
            file_name.replace(0, file_proto1.length(), "");
        else
            file_name.replace(0, file_proto2.length(), "");

#if defined(_WIN32) || defined(WIN32)
        // Under Windows we need to remove all starting slashes
        while (!file_name.empty() && file_name[0] == '/')
            file_name.replace(0, 1, "");
#endif
    }
    else if (full_path.find("file:") == 0)
        fprintf(stderr, "Error - URL syntax invalid in \"%s\", use "
            "\"" URL_FILE_PROTOCOL_1 "\" or \"" URL_FILE_PROTOCOL_2 "\"\n",
            full_path.c_str());
    else if (full_path.find(':') > 2 && full_path.find(':') < 8)
        fprintf(stderr, "Error - can't handle URL protocol in \"%s\"\n",
                full_path.c_str());
    else
        file_name = full_path; // pass it through

    return file_name;
}

///////////////////////  UrnResolver


static const char *nextToken()
{
    const char *token = strtok(NULL, URN_TOKEN_SEP);

    return (token? token : "");
}


static bool substituteMacros
(
    vector<string> &macros,
    vector<string> &subs,
    string &str
)
{
    bool found = false;

    for (std::string::size_type i = 0; i < macros.size(); i++)
    {
        std::string::size_type at;

        // limit the maximum number of substitutions per macro
        for (int n = 0;
             n < 20 && (at = str.find(macros[i])) != string::npos; n++)
        {
            found = true;
            str.replace(at, macros[i].length(), subs[i]);
        }
    }

    return found;
}


static string nextToken( vector<string> &macros, vector<string> &subs )
{
    string token(nextToken());

    if (!token.empty())
    {
        int total = 0;

        // limit the maximum number of recursive substitutions
        while (total < 100 && substituteMacros(macros, subs, token))
            total ++;

        if (total >= 100)
        {
            fprintf(stderr, "Error - URN resolver file \"%s\""
                " seems to have infinite macro expansion in \"%s\", line %d\n",
                s_resolverFile.c_str(), token.c_str(), s_lineNo);
            token.erase();
        }
    }
    return token;
}


static bool resolverTryFile
(
    const std::string &xmittal_urn,
    const std::string &version,
    const std::string &rsl_file,
    std::string &file_name
)
{
    // Resolver File Description:
    // =========================
    // Comments: Start with a "#" and end on a newline
    //
    // Macro Substitution:
    //      Macros are defined as:
    //          DEFINE MACRO_NAME [substitution string]
    //      and de-referenced by:
    //          $(MACRO_NAME) or ${MACRO_NAME} or $MACRO_NAME
    //      Substitution is only done in the TRANSMITTAL lines.
    //
    // Pre-defined Macros:
    //      CUR_RESOLVE_DIR:  expands to the path part of the resolver file
    //
    // Typical file layout:
    //
    //      DEFINE SEDRIS_BASE file://localhost/D:\sedris\transmittals
    //
    //      TRANSMITTAL urn:sedris:... 4.1:stf:4.1 ${SEDRIS_BASE}\myfile.stf
    //      ...
    //

    if (xmittal_urn.empty() || rsl_file.empty())
        return false;

    // If we can't open the file, then we can't resolve
    FILE *file_p = fopen(rsl_file.c_str(), "r");

    if (!file_p)
        return false;

    s_resolverFile = rsl_file;

    vector<string> Macros;
    vector<string> Substitutions;

    // Add the Macro CUR_RESOLVE_DIR for the current RSL file
    Macros.push_back("$(" URN_KW_CUR_RES_DIR ")");
    Macros.push_back("${" URN_KW_CUR_RES_DIR "}");
    Macros.push_back("$" URN_KW_CUR_RES_DIR);

    string path(FileUtils::GetPathOnly(rsl_file, false));

    if (path.empty())
        path = FileUtils::GetCurrDir(false);

    Substitutions.push_back(path);
    Substitutions.push_back(path);
    Substitutions.push_back(path);

    // Treat URL_FILE_PROTOCOL_2 as a macro for URL_FILE_PROTOCOL_1
    Macros.push_back(URL_FILE_PROTOCOL_2);
    Substitutions.push_back(URL_FILE_PROTOCOL_1);

    bool found = false;
    char buff[10000]; // maximum line length
    s_lineNo = 0;

    while (!found && (fgets(buff, 10000, file_p) != NULL))
    {
        s_lineNo++;

        if (strchr(buff, URN_COMMENT_CHAR) != NULL)
            *(strchr(buff, URN_COMMENT_CHAR)) = '\0';

        char *str = strtok(buff, URN_TOKEN_SEP);
        if (!str || !*str)
            continue;

        string token(str);

        if (token == URN_KW_TRANSMITTAL)
        {
            token = nextToken(Macros, Substitutions);

            if (token.empty())
            {
                fprintf(stderr, "Error - URN resolver file \"%s\""
                    " has TRANSMITTAL missing URN at line %d\n",
                    rsl_file.c_str(), s_lineNo);
                break;
            }

            if (token != xmittal_urn)
                continue;

            token = nextToken(Macros, Substitutions);

            if (token.empty())
            {
                fprintf(stderr, "Error - URN resolver file \"%s\""
                    " has TRANSMITTAL missing VERSION at line %d\n",
                    rsl_file.c_str(), s_lineNo);
                break;
            }

            if (!version.empty() && token != version)
            {
                fprintf(stderr, "Warning - URN resolver file \"%s\""
                    " has TRANSMITTAL with invalid VERSION \"%s\""
                    " at line %d, expected \"%s\"\n",
                    rsl_file.c_str(), token.c_str(),
                    s_lineNo, version.c_str());
                continue;
            }

            token = nextToken(Macros, Substitutions);

            if (token.empty())
            {
                fprintf(stderr, "Error - URN resolver file \"%s\""
                    " has TRANSMITTAL missing URL at line %d\n",
                    rsl_file.c_str(), s_lineNo);
                break;
            }
            file_name = token;
            found = true;
        }
        else if (token == URN_KW_DEFINE)
        {
            token = nextToken();

            if (token.empty())
            {
                fprintf(stderr, "Error - URN resolver file \"%s\""
                    " has DEFINE missing MACRO_NAME at line %d\n",
                    rsl_file.c_str(), s_lineNo);
                break;
            }
            string macro_name(token);
            string tmp;

            token = nextToken(); // token could be empty, but that's valid

            tmp = "$";
            tmp += macro_name;
            Macros.push_back(tmp);
            Substitutions.push_back(token);

            tmp = "$(";
            tmp += macro_name + ")";
            Macros.push_back(tmp);
            Substitutions.push_back(token);

            tmp = "${";
            tmp += macro_name + "}";
            Macros.push_back(tmp);
            Substitutions.push_back(token);
        }
        else
        {
            fprintf(stderr, "Warning - URN resolver file \"%s\""
                " has unknown token \"%s\" at line %d\n",
                rsl_file.c_str(), token.c_str(), s_lineNo);

            // get to end of current line
            while (*nextToken())
                ;
        }

        // If additional tokens are found, there is probably an error
        // in the file, so report it
        token = nextToken();

        if (!token.empty())
        {
            fprintf(stderr, "Warning - URN resolver file \"%s\""
                " has unrecognized token \"%s\" at line %d\n",
                rsl_file.c_str(), token.c_str(), s_lineNo);
        }
    }
    fclose(file_p);
    return found;
}


std::string UrnResolver::Resolve
(
    const std::string &xmittal_urn,
    const std::string &version,
    const std::string &rsl_file
)
{
    string ret;

    resolverTryFile(xmittal_urn, version, rsl_file, ret);

    return ret;
}


std::string UrnResolver::ResolvePaths
(
    const std::string &xmittal_urn,
    const std::string &version,
    const std::string &rsl_file,
    const std::string &paths,
    char separator
)
{
    string trim_path(trimFront(paths));
    string file_name;

    // special case with no paths, but we still need to try in the
    // current directory!
    if (trim_path.empty())
    {
        resolverTryFile(xmittal_urn, version, rsl_file, file_name);
        return file_name;
    }
    char seps[] = { separator, 0 };
    char *cpaths = new char[trim_path.length() + 1];

    strcpy(cpaths, trim_path.c_str());
    char *path = strtok(cpaths, seps);

    while (path)
    {
        string rsl_fpath(FileUtils::CombinePaths(string(path), rsl_file));

        if (resolverTryFile(xmittal_urn, version, rsl_fpath, file_name))
            break;

        path = strtok(NULL, seps);
    }
    delete[] cpaths;
    return file_name;
}


std::string UrnResolver::MangleUrn( const std::string &urn )
{
    if (urn.empty())
        return urn;

    char ret[10];
    int val=0, a=31415, b=27183;

    for (std::string::size_type i=0; i < urn.length(); i++, a *= b)
        val = (a * val + urn[i]);

    sprintf(ret, "%0X", val);

    return ret;
}
