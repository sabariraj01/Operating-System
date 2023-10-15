# Write a shell script to translate all the characters to lower case in a given text file.

echo -n "Enter a text file name : "
read file
 
if [ ! -f $file ]
then
	echo "$file not a file!"
	exit 1
fi
cat $file | tr '[A-Z]' '[a-z]'
