#/bin/bash

# Some variables
file="integer.txt"	# file to read
lock="${file}.lock"	# lock file

re='[+-]?[0-9]+$'	# regression to searching for integer
num=0			# variable to save integer read


# Check if file exist
if [ ! -f $file ]	# If file does not exit
then
	echo 0 > $file	# then create file with 0
fi


# Check if there is another process using this file
while [ -f $lock ]	# while lock file exists
do
	:		# do nothing
done


# File is ready, start reading and appending
ln -s $file $lock	# creat a lock file 

while read line		# read file line by line
do
	for word in $line	# read each word in line
	do
		if [[ $word =~ $re ]]	# integer detected
		then
			num=$word	# save to num
		fi
	done
done < $file

((num++))		# increase num by 1
echo $num >> $file	# append num to file
	
rm $lock		# remove lock file
