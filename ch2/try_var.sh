#!/bin/sh

salutation="Hello"
echo $salutation
echo "the program $0 is now running"
echo "the second parameter was $2"
echo "the first parameter was $1"
echo "the program list was $*"
echo "the user home dir is $HOME"

echo "please entering a new greeting"
read salutation

echo $salutation
echo "the script is now complete"
exit 0

