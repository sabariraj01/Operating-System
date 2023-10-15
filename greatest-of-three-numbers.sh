# Write a script to find the greatest of three numbers (numbers passed as command line parameters).

num1=$1
num2=$2
num3=$3
# Compare the numbers
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]; then
  echo "Greater Number is:" $num1
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]; then
  echo "Greater Number is:" $num2
else
  echo "Greater Number is:" $num3
fi
