# Write a shell script that accepts two directory Names as arguments and deletes those files in
# the first directory which are similarly Named in the second directly. Note: Contents should also
# match inside the files.

read -p "Enter the first directory name: " dir1
read -p "Enter the second directory name: " dir2

# Iterate over the files in the first directory.
for file in "$dir1"/*; do

  # Check if the file exists in the second directory.
  if [[ -f "$dir2/$file" ]]; then

    # Check if the contents of the files match.
    if [[ "$(cat "$dir1/$file")" == "$(cat "$dir2/$file")" ]]; then

      # Delete the file from the first directory.
      rm "$dir1/$file"
    fi
  fi
done
