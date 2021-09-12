#!bin/sh

./ex2 &

for i in 1 2 3
do
	echo $i iteration
	pstree | grep ex2
	sleep 5
done
