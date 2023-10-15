# Write a script called hello which outputs the following: 
# • your userName 
# • the time and date 
# • who is logged on 
# • also output a line of asterices (*********) after each section.



user=$(whoami)
date=$(date)
logged_on_users=$(who)

echo "Your username: $user"
echo "*********"
echo "Current date and time: $date"
echo "*********"
echo "Currently logged on users: $logged_on_users"
echo"*********"
