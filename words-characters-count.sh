 # Write a script to compute no. of characters and words in each line of given file.

echo "Enter the filename"
read file
c=`cat $file | wc -c`
w=`cat $file | wc -w`
echo "Number of characters in $file is $c"
echo "Number of words in $file is $w"
