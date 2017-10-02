README - name_change.pl
-----------------------

This script will replace strings globally throughout a file using exact
matching and word boundaries.  The source of the the replacement strings are
files with the extension 'nch', 'nch.1', through 'nch.n'.  The format of these 
files is simply key<=>value pairs.  For more information on the format of these 
files please refer to the section below called "nch File Format".  When running
this script, the default location that the script looks for the 'nch' files is 
the current working directory, i.e. the directory in which you invoke the script.
This default behaviour can be changed with command line options.  Once 
the 'nch' files have been parsed, then the script looks for all files in the 
current working directory that match the extensions provided below:

     - cpp
     - hpp
     - c
     - h

If you would like to change or add to the extensions listed above please refer
to the FAQ section below.  The default source directory can be changed with the
-s command line option.  The argument supplied with this option must be the 
directory that you want to search for the files with the chosen extensions to 
perform the string replacements on.  The default searching behaviour of this 
script is not to search recursively through subdirectories.  This default 
behaviour can be changed with a command line option.  The script, by default, 
makes backups of all files that are changed (this default behaviour can be 
changed with a command line option).  If after the script is done running and 
you decide that you don't want to keep the changes,  run the script again with 
the exact same arguments as the previous time and add the -r option to the 
command line options.  This will revert the changed files back to the version 
before you ran the script. 

*****WARNING*****
When running the script multiple times on the same files, be sure that the 
key<=>value string replacements in the 'nch' files are mutually exclusive to
avoid unwanted changes.  For more examples of such a situation please consult 
the FAQ section below.


Usage:
------
     name_change.pl [OPTIONS]

         -b        don't keep backup files (default is to keep backup files)
         -d        delete all the backup, 'nbk', files
         -f        be recursive (default is non-recursive)
         -i <file> use an individual 'nch' file in the current working 
                   directory, the directory specified in the -s option, or
                   the directory specified in the -n option.  The -n option
                   takes precedence over the -s and current working directory
         -h        this usage message
         -n <dir>  <dir> is the directory where the script should
                   look for the 'nch' files
         -r        revert to previous version using backup, 'nbk', files
         -s <dir>  specifies the source directory to use
         -v        verbose output



Explanation of Options:
-----------------------

  -b        This option tells the script not to keep backup files for later
            use with the -r option.  The default is to keep backup copies
            of changed files until you are satisfied with the changes and 
            then you can run the script again with the -d option to remove 
            the backup, 'nbk', files.
  -d        This option tells the script to delete the backup, 'nbk', files.  
            To use this option you must specify the same options as you 
            originally did and add the '-d' to it.  This option is not 
            selected by default.
  -f        This option tells the script that you want it to recurse
            through the subdirectories of the source directory.  The default
            is a non-recursive search for the specified files.
  -i <file> This option allows you to select a single 'nch' <file> from the 
            currently selected 'nch' file directory.  Please refer to the -n 
            option for more information on selecting a directory as the location
            of your 'nch' files.
  -h        Displays the usage message.
  -n <dir>  This option allows you to select the directory where the 'nch' 
            file(s) reside.  If this option is not specified then the default
            behaviour is to search the current working directory for the files.
  -r        This option is to revert previous changes made.  To use this
            option you must specify the same options as you originally did
            and add the '-r' to it.  This option will only revert the latest 
            changes made from the most recent run of the script. This option 
            is not selected by default.
  -s <dir>  This option allows you to select the source directory to be used.
            If this option is not used then the default behaviour is to search 
            the current working directory for the specified file extensions.
  -v        Turn on verbose mode.

nch File Format:
----------------
The format of the 'nch' file is simply key<=>value pairs:

FROM_STRING   TO_STRING
.             .
.             .

The columns are delimited by whitespace so you can have one or more spaces,
tabs, etc. so that you can make the files more readable.  Comments can be 
included in the files and must start with the '#' symbol.  There is no limit 
to the number of 'nch' files that the script can read in a single directory, 
which allows flexibility for the categorization of your strings to be replaced.


FAQ
---
Q:  How can I get the script to recognize more file extensions?
A:  If there are any extra extensions that you need included just add them
    to the subroutine called all_types at the end of the file.

    -- for example, if you wanted to include the file extension 'cc' then you 
       would add the lines-
                       "||
                       /^.*\.cc$/"
       like this:

sub all_types
{
   (
    /^.*\.cpp$/
    ||
    /^.*\.hpp$/
    ||
    /^.*\.c$/
    ||
    /^.*\.h$/
    ||
    /^.*\.inl$/
==> ||          
==> /^.*\.cc$/
    ) &&
       push(@tmp_files, $File::Find::name);
}
--------------------------------------------------------------------------------

Q:  Can I run the script on the same files more than once?
A:  Yes, but only if you are sure that you are not using any strings that 
    replace each other, in other words they need to be mutually exclusive or 
    you will be replacing the same strings over and over which will not give 
    you the desired results if you run the script an even number of times.  
    For example, if the 'nch' file has the following strings then each time 
    you run the script they will replace each other:

    :
    :
    Sample_from_string   Sample_to_string
    Sample_to_string     Sample_from_string
    :
    :
--------------------------------------------------------------------------------

Q:  Can a string to be replaced be divided across two lines, for example:
    
    foo = bar.baz.
            bob.dan;

    and the script is trying to match bar.baz.bob.dan and change it to 
    bam.boom.dan.bob?
A:  No, the string can not be matched across line boundaries.  Part of making
    sure that exact string replacement happens requires using word boundaries
    as a delimiter which includes newlines.  To remedy this problem you need to
    put the whole string together on a single line.
--------------------------------------------------------------------------------

Q:  I'm getting the error:
    "./name_change.pl: No such file or directory"
    What's causing this?

A:  Most likely you'll need to check that the first line of the script matches
    the path to Perl on your system.  To check where your installation of Perl
    resides you can type something on the command line to the effect of:

    >which perl
    /usr/local/bin/perl
    >
    
    Then make sure that the first line of the script matches that
    path.  If nothing comes back from the which statement, or whatever you use 
    to find out where something resides on your file system, then you need to 
    make sure that Perl is installed and that it's path is in in your 
    Environment Variable PATH.
--------------------------------------------------------------------------------
