echo Enter the Number:
read a

s=$(($a % 2))

if [ $s -eq 0 ]
then 
	echo $a is a even Number
else
	echo $a is odd numer
fi