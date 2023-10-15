read n
c=0
for(( i=2;i<=n;i++ ))
do
    if (( n%i==0 ))
    then
        c=$(( c+1 ))
    fi
done

if (( c==0 ))
then
    echo "Not Prime"
else 
    echo "Prime"
fi
