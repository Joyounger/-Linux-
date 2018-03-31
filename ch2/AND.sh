#!/bin/sh

touch file_one
rm -f file_two

if ([ -f file_one ] && echo "hello" && [ -f file_two ] && echo "in there")
then
	echo "in if"
else
	echo "in else"
fi

exit 0

