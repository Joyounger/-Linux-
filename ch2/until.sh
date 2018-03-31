#!/bin/sh

# echo $LOGINNAME
read LOGINNAME

until [ "$LOGINNAME" = "thief" ]
do
	echo "no warning!"
	read LOGINNAME
done

echo "warning!"
