# Write a shell script that, given a file Name as the argument will write the even numbered line
# to a file with Name evenfile and odd numbered lines to a file called oddfile

if [ $# -eq 0 ]; then
echo "No file name provided as argument."
exit 1
fi

if [ ! -f $1 ]; then
echo "File not found."
exit 1
fi
count=1

while read line; do
# Determine if line is even or odd
if [ $((count%2)) -eq 0 ]; then
# Write even line to evenfile
echo $line >> evenfile
else
# Write odd line to oddfile
echo $line >> oddfile
fi
# Increment line counter
count=$((count+1))
done < $1
echo "Lines written to oddfile and evenfile successfully."
