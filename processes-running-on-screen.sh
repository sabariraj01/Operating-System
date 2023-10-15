# Write a shell script to display the processes running on the system for every 30 seconds, but
# only for 3 times.

for i in 1 2 3 // or for(( i=1;i<=3;i++ ))
do
	echo "------------------------------------------------------------------"
	ps -e
	echo "******************************************************************"
	sleep 3
done
