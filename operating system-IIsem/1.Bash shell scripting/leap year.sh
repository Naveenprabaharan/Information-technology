echo enter the year:
read y

a=$(($y % 400))
e=$(($y % 100))
i=$(($y % 4))

if [ $a -eq 0 ]
then 
	echo $y is a leap year
elif [ $e -eq 0 ]
then 	
	echo $y is not a leap year
elif [ $i -eq 0 ]
then 
	echo $y is a leap year
else
	echo $y is anot leap year
fi