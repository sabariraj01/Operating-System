# Write the shell script which will replace each occurrence of character c with the characters chr in a string s. It should also display the number of replacements.

echo "Enter a string:"
read string

c=$(echo "$string" | grep -o "c" | wc -l)
new_string=$(echo "$string" | tr 'c' 'a')

echo "New string is $new_string and it is replaced $c times.."
