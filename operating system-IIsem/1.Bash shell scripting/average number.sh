echo Enter the total number size :
read a

i=0
sum=0
while [ $i -lt $a ]
do 
	echo enter the Number:
	read num
	sum=$(($sum + $num))
	((i++))
done

avarge=$(($sum / $i))
echo avarge of enter $i number is $avarge