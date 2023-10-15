# Write a shell script to echo the string length of the given string as argument.

read -p "Enter a string: " string
len=${#string}
echo "The length of the string is $len"
