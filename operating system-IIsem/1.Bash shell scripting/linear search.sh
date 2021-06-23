echo Enter the Array size:
read size

declare -a array

i=0
while [ $i -lt $size ]
do
	echo enter array element:
	read a
	array[$i]=$a
	((i++))
done

echo Enter the element to search:
read s

i=0
flag=0
while [ $i -lt $size ]
do
	b=${array[$i]}
	if [ $b -eq $s ]
	then 
		l=$(($i + 1))
		echo $s present in $l
		flag=1
	fi
	
	i=$(($i + 1))
done
	
if [ $flag -eq 0 ]
then 
	echo Element $s not present in array
fi