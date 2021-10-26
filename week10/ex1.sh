#!/bin/bash
touch _ex1.txt
echo "Ignat" >> _ex1.txt
link _ex1.txt _ex1_1.txt
link _ex1.txt _ex1_2.txt
ls -i _ex1.txt >> ex1.txt
ls -i _ex1_1.txt >> ex1.txt
ls -i _ex1_2.txt >> ex1.txt
