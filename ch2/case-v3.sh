#!/usr/bin

echo "is it morning? please answer yes or no"
read timeofday

case "$timeofday" in
	yes | y | Yes | YES )
		echo "good morning"
		echo "up bright and aerly this morning"
		;;
	[nN]* )
		echo "good afternoon"
		;;
	* )
		echo "answer not recognized"
		echo "please answer yes or no"
		exit 1
		;;
esac

exit 0

