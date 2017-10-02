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

#ifndef _URN_Resolver_h
#define _URN_Resolver_h

#include <string>

/** @file URN_Resolver.h
@author Gregory A. Hull, Marcus A . Martin (SAIC)
@author Warren Macchi (Accent Geographic)
@brief Declaration of UrnResolver and FileUtils.
*/

#define URN_SEDRIS_FILE      "sedris.rsl"
#define URN_CURR_VERSION     "4.1:stf:4.1"
#define URN_RESOLVE_ENV      "SEDRIS_RESOLVER_PATH"

#define URN_COMMENT_CHAR    '#'
#define URN_TOKEN_SEP       " \t\n\r"
#define URN_KW_DEFINE       "DEFINE"
#define URN_KW_TRANSMITTAL  "TRANSMITTAL"
#define URN_KW_CUR_RES_DIR  "CUR_RESOLVE_DIR"

#define URL_FILE_PROTOCOL_1 "file:///"
#define URL_FILE_PROTOCOL_2 "file://localhost/"


/** General File System utilities.
*/
class FileUtils
{
public:

    static const char SystemSlash;
    static const char SystemEnvSeparator;
    static const char OtherSlash;
    static const char OtherEnvSeparator;

    static const char WindowsSlash;
    static const char WindowsEnvSeparator;
    static const char UnixSlash;
    static const char UnixEnvSeparator;

    /** Get path part from a full path name (default includes last "/" or "\").
        @note Works with both Unix and Windows style paths, but doesn't
            change the style that was passed in.
        @note If no path information is found, returns the empty string.
        @see ConvertSlashes()
    */
    static std::string GetPathOnly( const std::string &full_path, bool with_slash=true );

    /// Get file name part from a full path name
    static std::string GetFileOnly( const std::string &full_path );

    /// Get name (file name - extension) from a full path name
    static std::string GetFileOnlyNoExt( const std::string &full_path );

    /// Get file extension (the part _after_ ".") from a full path name
    static std::string GetFileExt( const std::string &full_path );

    /// Get the current working directory (default includes last "/" or "\")
    static std::string GetCurrDir( bool with_slash=true );

    /** Sets the current working directory.
        @note Since many paths could point to the same directory, @path
            may not equal what GetCurrDir() returns.
        @return true if successful
    */
    static bool SetCurrDir( const std::string &path );

    /** Converts the input file path into an absolute file path.
        @note The path may include the "file:///" protocols, see
            @PurgeFileProtocol().
        @warning This method uses standard Windows or Unix function calls,
            so the returned path will be in the local system's path. If
            you call this method using a path inconsistent with the system
            unreliable results could occur.
        @warning In Unix, this method will not succeed (returns empty) if
            the file/path does not exist. This is not true in Windows, which
            doesn't care whether the file/path exists.
    */
    static std::string GetAbsolutePath( const std::string &file_path );

    /** Combines two file paths using the specified or default slash
        separator.
        @note Path separators are converted using ConvertSlashes().
        @note If @p first_part is empty, no path separator is used for
            the combined path. For example, "" and "../file" returns
            "..[/ or \]file" (the slash being as specified).
        @note The combined path is run through ConvertSlashes().
    */
    static std::string CombinePaths( const std::string &first_part,
                                        const std::string &second_part,
                                        char slash = FileUtils::SystemSlash );

    /** Convert slashes in path to the specified or default slash separator,
        and remove extra slashes.
        @note If the path starts with two slashes, the path is assumed to
            be a Windows network path and the two slashes are kept.
    */
    static std::string ConvertSlashes( const std::string &full_path,
                                        char slash = FileUtils::SystemSlash );

    /** Purges the URL_FILE_PROTOCOL_1 and URL_FILE_PROTOCOL_2 from a
        URL (e.g. from a resolver file resolution).
        @note If the protocol can't be guessed, @p url is returned. This
            allows for URLs that don't have a protocol in them (like
            "D:\somewhere\file.stf").
        @note Failure or unhandled protocols print error and return empty
            string.
    */
    static std::string PurgeFileProtocol( const std::string &url );
};


/** Finds SEDRIS Resolver files and resolves a URN into a file name.
Options for URN resolution include:
<ol>
<li>Pass in a URN and resolver file name (which may include a path).</li>
<li>Pass in a set of paths and a resolver file name (which shouldn't
include a path). The paths passed-in can include the standard path
system shortcuts, such as ".".</li>
</ol>

Note that the order and paths in which resolution is done is completely
controlled by the caller.
*/
class UrnResolver
{
public:

    /** Attempts to resolve a URN by opening the specified @p rsl_file.
        @note Since resolution can return all protocols, you should call
            FileUtils::PurgeFileProtocol() to get the actual file name.
        @return The resolved file name if successful, empty string if unable
         to resolve the URN.
    */
    static std::string Resolve( const std::string &xmittal_urn,
                                const std::string &version,
                                const std::string &rsl_file );

    /** Attempts to resolve a URN by opening the specified @p rsl_file using
        the paths specified in @p paths.
        @note The paths can use the Unix/Windows path separators, such as ":"
            or ";".
        @note Since resolution can return all protocols, you should call
            FileUtils::PurgeFileProtocol() to get the actual file name.
        @return The resolved file name if successful, empty string if unable
         to resolve the URN.
    */
    static std::string ResolvePaths( const std::string &xmittal_urn,
                                const std::string &version,
                                const std::string &rsl_file,
                                const std::string &paths,
                                char separator = FileUtils::SystemEnvSeparator );

    /** Mangles the URN string.
        Note that you can't recover the URN from the returned string.
    */
    static std::string MangleUrn( const std::string &urn );
};


#endif // _URN_Resolver_h
