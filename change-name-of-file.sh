# Write a shell script that changes the Name of the files passed as arguments to lowercase.

files=$@
for file in $files; do
  new_name=$(echo "$file" | tr '[A-Z]' '[a-z]')
  mv "$file" "$new_name"
done
