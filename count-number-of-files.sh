# Write a script that will count the number of files in each of your subdirectories.

current_directory=$(pwd)
for subdirectory in "$current_directory"/*; do

  # If the subdirectory is a directory, count the number of files in it.
  if [[ -d "$subdirectory" ]]; then
    num_files=$(find "$subdirectory" -type f | wc -l)
    echo "$subdirectory: $num_files"
  fi
done
