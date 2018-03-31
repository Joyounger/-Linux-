#!/bin/sh

if [ -f /bin/bash ]
then
	echo "file /bin/bash exists"
fi

if [ -d /binbash ]
then
	echo "/bin/bash is a directory"
else
	echo "/bin/bash is NOT a directory"
fi
