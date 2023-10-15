# Write a script to check whether the given string is a palindrome

read -p "Enter a string: " string
reversed_string=$(echo "$string" | rev)
if [[ "$reversed_string" == "$string" ]]; 
then
  echo "The string is a palindrome."
else
  echo "The string is not a palindrome."
fi
