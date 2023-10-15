# Write a shell program to concatenate to two strings given as input and display the resultant
# string along with its string length. 

echo "Enter two strings to conacatinate : "
echo "Enter first string: "
read a 
echo "Enter second string: "
read b
c=$a$b
l=${#c}
echo "Concatenated string is $c and the length of the string is $l"
