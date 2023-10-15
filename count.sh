# Write a shell program to count the following in a text file. 
#  • Number of vowels in a given text file.
#  • Number of blank spaces.
#  • Number of characters. 
#  • Number of symbols.
#  • Number of lines

vo=$(grep -io "[aeiou]" $fil | wc -l)

sp=$(grep -o " " $fil | wc -l)

ch=$(wc -m < $fil)

li=$(wc -l < $fil)

echo "Number of vowels: $vo"
echo "Number of blank spaces: $sp"
echo "Number of characters: $ch"
echo "Number of lines: $li"
