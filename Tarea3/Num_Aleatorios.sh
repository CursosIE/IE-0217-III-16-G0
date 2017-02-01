#!/bin/bash

i=0

while [ $i -le $1 ]
do
	printf $RANDOM 
	printf " "
	i=$(($i+1))
done
