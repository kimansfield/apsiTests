#!/bin/sh

echo 'Hello World'

cleanup()
{
	ssh $USER${SERVER[0]} $TEST_DIR/./runKillAll >/dev/null 2>&1 &
	ssh $USER${CLIENT[0]} $TEST_DIR/./runKillAll >/dev/null 2>&1 &
	return $?
}



ssh $USER${SERVER[0]} workspace/apsiTests/./runServer >/dev/null 2>&1 &

for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
do
	curl --socks5-hostname localhost:1080 google.com &
done

cleanup
