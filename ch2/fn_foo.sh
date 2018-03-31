#!/bin/sh

sample_text="global var"

foo () {
	local sample_text="local var"
	echo "function foo is executing"
	echo "$sample_text"
}


echo "script statring"
echo "$sample_text"

foo

echo "script ended"
echo "$sample_text"

exit 0
