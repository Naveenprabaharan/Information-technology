echo Enter array size:
read size

declare -a array
i=0
while [ $i -lt $size ]
do
	echo Enter the array element:
	read v
	array[$i]=$v
	((i++))
done

i=0
sum=0
while [ $i -lt $size ]
do
	b=${array[$i]}
	d=$(($b *$b))
	sum=$(($sum + $d))
	((i++))
done
echo element sum of all array square values are $sum