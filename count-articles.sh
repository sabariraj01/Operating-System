# Write a shell script that counts English language articles (a, an, the) in a given text file.

echo "Enter the filename: "
read fil

a=$(grep -o "\ba\b" "$fil" | wc -l)
an=$(grep -o "\ban\b" "$fil" | wc -l)
the=$(grep -o "\bthe\b" "$fil" | wc -l)

echo "'a' occured $a times.."
echo "'an' occured $an times.."
echo "'the' occured $the times.."
