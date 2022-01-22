#!/bin/bash

g++ h.cpp -Wall -o h.out
g++ rand.cpp -Wall -o rand.out
g++ stupid.cpp -Wall -o stupid.out

while ((1))
do
	./rand.out > input
	./h.out < input > hout
	./stupid.out < input > sout
	cat input
	diff hout sout
	if (($? != 0))
	then
		break;
	fi
done
