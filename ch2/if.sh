#!/bin/sh


echo "is it morning? please answer yes or no"
read timeofday

if [ $timeofday = "yes" ]; then
	echo "good morning"
else if [ $timeofday = "no" ]; then
		 echo "good afternoon"
	 else
		 echo "good evening"
	 fi
fi

exit 0
