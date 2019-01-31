#!/bin/sh

echo Hello World


./runServer &
./runClient &

#while :
#do
for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
do
	curl -socks5 localhost:1080 http://www.google.com &
done
sleep 10s
#sleep 90s

processes=`ps aux | grep apsi | wc | cut -d" " -f7`
#echo "processes = $processes"

if [ "$processes" -gt "4" ]; then
	echo "Error: bug #22 still there"
	./runKillAll
	exit 1
fi

echo "bug #22 test complete"

#done

./runKillAll

exit 0
