# Write a shell script which reads the contents in a text file and removes all the blank spaces in
# them and redirects the output to a file.

echo "Enter the directory of the file:"
read file_path
if [ ! -f "$file_path" ]; then
  echo "Error: File not found."
  exit 1
fi

file_contents=$(cat "$file_path" | tr -d ' ')

echo "Modified file contents:"
echo "$file_contents"
