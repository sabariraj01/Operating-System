# 5. Write a shell script that deletes all the even-numbered lines in a text file.

#!/bin/bash
# Check that a file has been provided as an argument
if [ $# -eq 0 ]; then
    echo "Please provide a file name as an argument"
    exit 1
fi

# Check that the file exists and is a regular file
if [ ! -f "$1" ]; then
    echo "$1 is not a file or does not exist"
    exit 1
fi

# Delete all even-numbered lines in the file using sed
sed -i.bak '1d;n;d' "$1"

# Print a confirmation message
echo "Deleted all even-numbered lines in $1"
