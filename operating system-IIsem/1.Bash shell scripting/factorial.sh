echo enter to find the factorial:
read a
i=1		
sum=0
while [ $i -le $a ]
do
	if [ $i -eq 1 ]
	then
	sum=$(( $i * 2))
	i=3
	
	else
	sum=$(( $sum * $i))
	i=$(($i+1))
	fi
done

echo $sum