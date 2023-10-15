# Write a shell script that displays the last modification time of any file.

echo "Enter a filename: "
read n
if [ ! -f $n ]
then
	echo "Invalid file "
	exit 1
fi
echo "$n is last modified on $(stat -c %x $n)"
