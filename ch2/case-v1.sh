#!/bin/sh

echo "is it morning, please anser yes or no"
read timeofday

case "$timeofday" in
yes) echo "good morning";;
no)  echo "good afternoon";;
y)   echo "good morning";;
n)   echo "good afternoon";;
*)   echo "sory, answer not recgnized";;
esac

exit 0


