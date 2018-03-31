#!/bin/sh

until who | grep "$1" > /dev/null
do
	sleep 60
done

# now ring the bell and announe the expected user

#echo -n '\a'
echo "**** "$1" has just logged in ****"
exit 0
