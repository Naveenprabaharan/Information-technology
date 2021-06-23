echo Enter the Number:
read num

N=$((num / 2))
i=2
flag=0
while [ $i -lt $N ]
do
	m=$((num % $i))
	if [ $m -eq 0 ]
	then 
		echo $num is not a prmie number!
		flag=1
	fi
	((i++))
done


if [ $flag -eq 0 ]
then 
	echo $num is prime Number!
fi