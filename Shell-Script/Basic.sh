#! /usr/bin/bash

echo "Nhap a"
read a

echo "Nhap b"
read b

if [ $a -gt $b ] 
then
echo "a lon hon b"
elif [ $a -eq $b ]
then
echo "a bang b"
elif [ $a -lt $b ]
then
echo "a be hon b"
fi
