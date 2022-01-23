#!/bin/bash

g++ c.cpp -Wall -o c.out
g++ stupid.cpp -Wall -o stupid.out
g++ rand.cpp -Wall -o rand.out

while ((1))
do
	./rand.out > input
	./c.out < input > cout
	./stupid.out < input > sout
	cat input
	diff sout cout
	if (($? != 0))
	then
		break;
	fi
done
