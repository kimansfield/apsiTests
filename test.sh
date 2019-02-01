#!/bin/sh

echo Hello World


./runServer >/dev/null &
./runClient >/dev/null &

echo proxy is running

#while :
#do
echo start curl
for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
do
	curl -socks5 localhost:1080 http://www.google.com &
done
echo wait for curl
sleep 10s
#sleep 90s

echo done waiting
processes=`ps aux | grep apsi | wc | cut -d" " -f7`
echo "processes = $processes"

echo check for error
if [ "$processes" -gt "4" ]; then
	echo "Error: bug #22 still there"
	./runKillAll >/dev/null
	exit 1
fi

echo "bug #22 test complete"

#done

./runKillAll >/dev/null

exit 0
