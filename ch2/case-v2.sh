#!/bin/sh

echo "is it morning, please anser yes or no"
read timeofday

case "$timeofday" in
yes | YES | y | Yes ) 	echo "good morning";;
n* | N*)  				echo "good afternoon";;
*)   					echo "sory, answer not recgnized";;
esac

exit 0

