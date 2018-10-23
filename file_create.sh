i=0
#for ( i = 0; i <= 10; i++ ) 
while [ $i -lt 10 ];
do 
	touch $i
	i=$((i+1))
done
