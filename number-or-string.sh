# Write a script to check whether the given input is a number or a string.

#!/bin/bash

# Get the input from the user.
read -p "Enter a number or a string: " input

# Check if the input is a number.
if [[ $input =~ ^[0-9]+$ ]]; then
  echo "The input is a number."
else
  echo "The input is a string."
fi
