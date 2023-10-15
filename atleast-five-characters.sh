# Write a shell script that accepts a string from the terminal and echo a suitable message if it
# doesn’t have at least 5 characters including the other symbols.

read -p "Enter a string: " string
string_length=${#string}
if [[ $string_length -lt 5 ]]; 
then
  echo "The string is too short. It must have at least 5 characters."
else
  echo "The string is long enough."
fi
