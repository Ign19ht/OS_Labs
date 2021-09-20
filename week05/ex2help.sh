#!/bin/sh

file="integer.txt"
lock="${file}.lock"
flag="continue"

if [ -f $file ]
then
  echo 0 >> $file
fi

while [ "$flag" = "continue" ]
do
  if ln -sv $file $lock
  then
      cur=$( tail -n 1 $file)
      cur=$((cur+1))
      echo $cur >> $file
      echo $cur writed
      if [ $cur -gt 1000 ]
      then
        flag="stop"
      fi
    rm $lock
  fi
done


