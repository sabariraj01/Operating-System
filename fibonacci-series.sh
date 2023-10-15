# Write a script to print the Fibonacci series up to n terms.

read -p "Enter the number of terms: " n
a=0
b=1
echo "$a $b"
for i in $(seq 2 $n); do
  c=$((a+b))
  echo "$c"
  a=$b
  b=$c
done
