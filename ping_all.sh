CHECKING=${1}
echo $#

if [ $# -eq 0 ]; then
	echo "Usage: ./ping_all 192.168.1"
  exit 0
fi

for (( i=1; i <= 255; i++ ))
do
#	ping -c 1 $CHECKING.$i > /dev/null 2>&1;
	ping -c 1 $CHECKING.$i ;
	if [ $? -eq 0 ]; then
		echo "livehosts  $CHECKING.$i"
  fi
done

