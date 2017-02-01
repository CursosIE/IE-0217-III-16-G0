#!/bin/bash

i=0

while [ $i -le 100 ]
do
	printf $RANDOM 
	printf " "
	i=$(($i+1))
done
