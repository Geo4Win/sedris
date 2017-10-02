#! /usr/local/bin/perl -w

use Getopt::Std;
use File::Find;
use Cwd;

my @tmp_files;
my @nbk_files;
my @nch_files;
my @nch_dot_files;
my @found_list;
my @revert_files;
my @backup_files;
my $increment_file;
my $slurp_val;

# test the options and set vars

getopts('brhdfvs:n:i:', \%opts);

if($opts{"h"})
{
   # help option - prints out the help and usage message
   print("\n\nUsage:\n");
   print("------\n");
   print("     name_change.pl [OPTIONS]\n\n");

   print("         -b        don't keep backup files (default is to keep backup files)\n");
   print("         -d        delete all the backup, 'nbk', files\n");
   print("         -f        be recursive (default is non-recursive)\n");
   print("         -i <file> use an individual 'nch' file in the current working\n"); 
   print("                   directory, the directory specified in the -s option, or\n");
   print("                   the directory specified in the -n option.  The -n option\n");
   print("                   takes precedence over the -s and current working directory\n");
   print("         -h        this usage message\n");
   print("         -n <dir>  <dir> is the directory where the script should\n");
   print("                   look for the 'nch' files\n");
   print("         -r        revert to previous version using backup, 'nbk', files\n");
   print("         -s <dir>  specifies the source directory to use\n");
   print("         -v        verbose output\n\n\n\n");

   exit;

}

if($opts{"f"})
{
   $recursive_find = 1;
}
else # default
{
   $recursive_find = 0;
}

# The default will be to backup files that need changes
# The -b option will actually specify not to backup the
# files
if($opts{"b"})
{
   $backup = 0;
}
else
{
   $backup = 1;
}

# This option is for reverting changes
# When this option is added to the cammond line we expect
# that the same options were supplied plus this option
if($opts{"r"})
{
   $revert = 1;
}
else
{
   $revert = 0;
}

# This option is for setting the verbose flag
if($opts{"v"})
{
   $verbose = 1;
}
else
{
   $verbose = 0;
}

# set up the defaults first
$cwd_dir = cwd;
$source_dir = cwd;
$nch_files_dir = cwd;

# If the -s option was specified then check that the dir
# exists.  If so then set the absolute path with cwd and
# change back to
if($opts{"s"})
{
   $source_dir = $opts{"s"};
   if(chdir($source_dir))
   {
      $source_dir = cwd;
      chdir($cwd_dir);
   }
   else
   {
      die("Can't chdir to ($source_dir) from ($cwd_dir): Exiting script now.\n");
   }
}

# set up the nch_files_dir if -n option specified on command line
# -n and -i options are not longer dependent
if($opts{"n"})
{
   $nch_files_dir = $opts{"n"};
   if(chdir($nch_files_dir))
   {
      $nch_files_dir = cwd;
      chdir($cwd_dir);
   }
   else
   {
      die("Can't chdir to ($nch_files_dir) from ($cwd_dir): Exiting script now.\n");
   }
   
}

# set up var for -i option
if($opts{"i"})
{
   $use_one_nch_file = 1;
   $ind_nch_file = $opts{"i"};
   # check file existence using $nch_files_dir
   if($cwd_dir =~ m/\\/)
   {
      $separator = "\\";
   }
   else
   {
      $separator = "/";
   }
   if(-e $nch_files_dir.$separator.$ind_nch_file)
   {
      $ind_file_exists = 1;
   }
   else
   {
      $ind_file_exists = 0;
   }
}
else
{
   $use_one_nch_file = 0;
   $ind_nch_file = "";
   $ind_file_exists = 0;
}

# set up for the addition of -d option
# We expect that the same arguments are passed to script as 
# when the 'nbk' files were created so that we know where
# to search to remove them
if($opts{"d"})
{
   $delete_backups = 1;
}
else
{
   $delete_backups = 0;
}

# print out all values of options if verbose flag is on
if($verbose)
{
   print("\nThe current options are set as follows:\n");
   print("---------------------------------------\n\n");
   print("   -b => $backup\n");
   print("   -d => $delete_backups\n");
   print("   -f => $recursive_find\n");
   print("   -i => $use_one_nch_file  value=$ind_nch_file  file_exists=$ind_file_exists\n");
   print("   -n => $nch_files_dir\n");
   print("   -r => $revert\n");
   print("   -s => $source_dir\n");
   print("   -v => $verbose\n");
   print("   cwd => $cwd_dir\n\n");
}

# if the delete_backups flag is on then remove all backup 'nbk' files
# and exit when done
if($delete_backups)
{
   find(\&nbk_types, $source_dir);
   chomp(@nbk_files);
   foreach $nbk (@nbk_files)
   {
      if($nbk =~ m/^\//)
      {
	 push(@backup_files, $nbk);
      }
      else
      {
	 push(@backup_files, substr($nbk, 2));
      }
   }

   if($#backup_files == -1)
   {
      die ("No backup files found to remove\n");
   }
   else
   {
      if($verbose)
      {
	 print("\nlist of files to be deleted:\n");
	 print("----------------------------\n");
	 foreach $tmp (@backup_files)
	 {
	    print("\t$tmp\n");
	 }
      }

      $num_files = $#backup_files + 1; 
      # have to add 1 because it returns the last index (zero based)
      $num_deleted_files = unlink(@backup_files);
      if($num_files == $num_deleted_files)
      {
	 die("All backup files removed successfully\n");
      }
      else
      {
	 die(($num_files - $num_deleted_files) . " backup file(s) could not be removed\n");
      }
   }
   print("Done removing backup files.\n");
   print("Script Complete.\n");
   exit;
}

# if revert flag is on then find the files to revert and the revert them
# else do the name_change stuff
if ($revert)
{
   # find all files with extension "*.nbk" and rename them to 
   # the original name which is just minus the .nbk extension

   find(\&nbk_types, $source_dir);
   chomp(@nbk_files);
   foreach $nbk (@nbk_files)
   {
      if($nbk =~ m/^\//)
      {
	 push(@revert_files, $nbk);
      }
      else
      {
	 push(@revert_files, substr($nbk, 2));
      }
   }
   
   if($#revert_files == -1)
   {
      die ("No files found to revert\n");
   }
   
   if($verbose)
   {
      print("list of files to be reverted:\n");
      print("-----------------------------\n");
      foreach $tmp (@revert_files)
      {
	 print("\t$tmp\n");
      }
   }
   
   foreach $to_revert (@revert_files)
   {
      $reverted_name = $to_revert;
      substr($reverted_name, -4, 4) = "";
      rename($to_revert, $reverted_name) || 
	 die ("Couldn't revert $to_revert\n");
   }   
   print("Done reverting files.\n");
   print("Script Complete.\n");
   exit;
}



# Need to do all the meaty stuff here:
# ------------------------------------
#    -- find all nch.* files and find largest number
#    -- create for loop to go from 0 to largest number
#    -- find nch.* files (if index is 0 then just plain .nch)
#    -- load the nch files into hash
#    -- find the files with specified extensions
#    -- rename all keys to values in each file found
#    -- clear the hash when done and loop again



if($use_one_nch_file && $ind_file_exists)
{
   push(@nch_files, $nch_files_dir.$separator.$ind_nch_file);
   $loopSize = 0;
}
elsif($use_one_nch_file && !$ind_file_exists)
{
   die("The file ".$nch_files_dir.$separator.$ind_nch_file." does't exist. Exiting script now.\n");
}
else
{
#    -- find all nch.* files and find largest number
   find(\&nch_dot_types, $nch_files_dir);

   $loopSize = findLargest();
}

#print("the largest found is $loopSize\n");
#die();

for($iter = 0; $iter <= $loopSize; $iter++)
{
   # find(\&nch_types, $nch_files_dir);
   if($iter == 0)
   {
      find(\&nch_types, $nch_files_dir);
   }
   else
   {
      $increment_file = "nch.".$iter;
      find(\&nch_num_types, $nch_files_dir);
   }

   if($#nch_files == -1)
   {
      print ("No 'nch.$iter' files found.\n");
      next;
   }

   if($verbose)
   {
      print("\nlist of 'nch.$iter' files found:\n");
      print("-----------------------------\n");
      foreach $tmp (@nch_files)
      {
	 print("\t$tmp\n");
      }
   }

   foreach $filename (@nch_files)
   {
      chomp($filename);
      if($filename =~ m/^\//)
      {
      }
      else
      {
	 $filename = substr($filename, 2);
      }
      
      # open the file and read in all the lookup tables
      
      open(FILEHANDLE, "$filename") ||
	 die "Couldn't open $filename for reading\nExiting script\n";
      
      @names_to_change = <FILEHANDLE>;
      close(FILEHANDLE);
      chomp(@names_to_change);
      
      foreach $name (@names_to_change)
      {
	 chomp($name);
	 #removes any spaces at the beginning of the line
	 $name =~ s/^ +//;
	 
	 if((substr($name, 0, 1) ne "#") && ($name ne ""))
	 {
	    @line = split(/ +/, $name);
	    $lookup_table{$line[0]} = $line[1];
	    undef @line;
	 }
      }
      undef @names_to_change;
   }

   if($verbose)
   {
      print("\nThe list of key<=>value pairs in the hash:\n");
      print("------------------------------------------\n");
   }

   foreach $key (keys %lookup_table)
   {
      if($lookup_table{$key})
      {
	 if($verbose)
	 {
	    print("\t$key <=> $lookup_table{$key}\n");
	 }
      }
      else
      {
	 print("$key, has no associated value:  Removing entry in lookup table\n");
	 delete($lookup_table{$key});
      }
   }

   find(\&all_types, $source_dir);
   chomp(@tmp_files);

   if($verbose)
   {
      print("\nThe list of files found:\n");
      print("------------------------\n");
   }

   foreach $tmp (@tmp_files)
   {
      if($tmp =~ m/^\//)
      {
	 push(@found_list, $tmp);
      }
      else
      {
	 push(@found_list, substr($tmp, 2));
      }
      
      if($verbose)
      {
	 print("\t$tmp\n");
      }
   }

   # Now that we've found all the files and we have the lookup table
   # we need to open each of the files and parse each of the lines
   # for each of the keys and replace when found.

   if(@found_list != -1)
   {
      if($verbose)
      {
	 print("\nThe following files had changes:\n");
	 print("--------------------------------\n");
      }

      foreach $test (@found_list)
      {
	 if(open(FILEHANDLE, "$test"))
	 {
	    # This next line allows us to slurp the whole file at
	    # once into a single string
	    $slurp_val = $/;
	    undef $/;

	    $file_contents = <FILEHANDLE>;
	    close(FILEHANDLE);
	    
	    $/ = $slurp_val;

	    $my_tmp = $file_contents;

	    # This foreach loop actually does the global substitution
	    # using word boundaries
	    foreach $key (keys %lookup_table)
	    {
	       $value = $lookup_table{$key};
	       # this is the global substitution on word boundaries
	       $file_contents =~ s/\b$key\b/$value/g;
	    }

	    # This check is to see if the file changed
	    # If it didn't then we don't want to keep a backup
	    if($my_tmp ne $file_contents)
	    {
	       print("Modified file: $test level: $iter\n");
	       if($verbose)
	       {
		  print("\t$test\n");
	       }
	       
	       # if backup and the file with .nbk doesn't already exist
	       if($backup && !(-e $test.".nbk"))
	       {
		  $new_name = $test.".nbk";
		  rename($test, $new_name) ||
		     warn("-b option selected but couldn't backup(rename) $test\nNo changes made to $test.\n");
		  chmod(0775, $new_name) ||
		     warn "Couldn't chmod(0775, $new_name): $!\n";
		  #print("Renamed file: $test level: $iter\n");
	       }
	       else
	       {
		  chmod(0775, $test) ||
		     warn "Couldn't chmod(0775, $test): $!\n";
	       }

	       if(open(NEWFILE, ">$test"))
	       {
		  print NEWFILE ($file_contents);
		  close(NEWFILE);
		  if($backup)
		  {
		     chmod(0775, $test) ||
			warn "Couldn't chmod(0775, $test): $!\n";
		  }
	       }
	       else
	       {
		  # this file could not be opened for writing
		  # and needs to be added to the error log
		  # to be used at a later time possibly
		  print("$test could not be opened for writing\n");
		  print("No changes will occur in this file\n");
	       }
	      
	       
	    }
	    


	 }
	 else
	 {
	    # this file could not be opened for reading
	    # and needs to be added to the error log
	    # to be used at a later time possibly
	    print("$test could not be opened for reading\n");
	    print("No changes will occur in this file\n");
	 }
	 @file_contents = undef;
      }
   }
   # undef all file arrays and hashes before next round
   undef @nch_files;
   undef %lookup_table;
   undef @tmp_files;
   undef @found_list;
   print("Done processing level $iter\n");
}

print("Script Complete.\n");
   
sub all_types
{
   if($recursive_find)
   {
      (
       /^.*\.java$/
       ||
       /^.*\.cpp$/
       ||
       /^.*\.hpp$/
       ||
       /^.*\.c$/
       ||
       /^.*\.h$/
       ) &&
	  push(@tmp_files, $File::Find::name);
   }
   else
   {
      if($source_dir eq $File::Find::dir)
      {
	 (
	  /^.*\.java$/
	  ||
	  /^.*\.cpp$/
	  ||
	  /^.*\.hpp$/
	  ||
	  /^.*\.c$/
	  ||
	  /^.*\.h$/
	  ) &&
	     push(@tmp_files, $File::Find::name);
      } 
   }
}

sub nch_types
{
   if($nch_files_dir eq $File::Find::dir)
   {
      (
       /^.*\.nch*$/
       ) &&
	  push(@nch_files, $File::Find::name);
   }
}

sub nch_dot_types
{
   if($nch_files_dir eq $File::Find::dir)
   {
      (
       /^.*\.nch\..*$/
       ) &&
	  push(@nch_dot_files, $File::Find::name);
   }
}

sub nch_num_types
{
   if($nch_files_dir eq $File::Find::dir)
   {
      (
       /^.*\.$increment_file*$/
       ) &&
	  push(@nch_files, $File::Find::name);
   }
}

sub nbk_types
{
   if($recursive_find)
   {
      (
       /^.*\.nbk$/
       ) &&
	  push(@nbk_files, $File::Find::name);
   }
   else
   {
      if($source_dir eq $File::Find::dir)
      {
	 (
	  /^.*\.nbk$/
	  ) &&
	     push(@nbk_files, $File::Find::name);
      }
   }
}

sub findLargest{
   my ($largest);
   $largest = 0;
   foreach $_ (@nch_dot_files)
   {
      # print("$_\n");
      $tmp = substr($_, (rindex($_, ".") + 1), (length($_) - (rindex($_, ".") + 1)));
      if($tmp =~ /\D/)
      {
	 # print("$tmp has a non-digit character, skipping\n");
	 next;
      }
      if($tmp > $largest)
      {
	 $largest = $tmp;
      }
   }
   return $largest;
}
