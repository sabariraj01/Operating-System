# Write a shell program to simulate a simple calculator. 90)

add() 
{
  echo "$1 + $2 = $(($1 + $2))"
}

sub() 
{
  echo "$1 - $2 = $(($1 - $2))"
}

mul() 
{
  echo "$1 * $2 = $(($1 * $2))"
}

div() {
  if [ $2 -eq 0 ]; then
    echo "Division by zero is not possible.."
  else
    echo "$1 / $2 = $(($1 / $2))"
  fi
}

echo "Enter the operator : "
read operator
echo "Enter first number:"
read num1
echo "Enter second number:"
read num2

case $operator in
  +)
    add $num1 $num2
    ;;
  -)
    sub $num1 $num2
    ;;
  \*)
    mul $num1 $num2
    ;;
  /)
    div $num1 $num2
    ;;
  *)
    echo "Error: invalid operator"
    ;;
esac
