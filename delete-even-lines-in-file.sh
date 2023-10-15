# Write a shell script which deletes all the even numbered lines in a text file.

if [ $# -eq 0 ]; then
    echo "Enter file name as an argument"
    exit 1
fi

if [ ! -f "$1" ]; then
    echo "$1 is not a file or does not exist"
    exit 1
fi
sed -i.bak '1d;n;d' "$1"
echo "Deleted all even-numbered lines in $1"
