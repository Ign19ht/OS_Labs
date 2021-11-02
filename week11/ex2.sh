#!/usr/bin/bash
echo 'Ignat' >> lofsdisk/file1.txt
echo 'Petrov' >> lofsdisk/file2.txt
./ex2 > ex2.txt

mkdir -p lofsdisk/bin
mkdir -p lofsdisk/lib64
mkdir -p lofsdisk/usr/lib
mkdir -p lofsdisk/usr/lib64
mkdir -p lofsdisk/lib/x86_64-linux-gnu

cp /bin/bash lofsdisk/bin
cp /bin/ls lofsdisk/bin
cp /bin/cat lofsdisk/bin
cp /bin/echo lofsdisk/bin

ldd /bin/bash | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
ldd /bin/ls | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
ldd /bin/cat | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
ldd /bin/echo | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}

cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/
cp ex2 lofsdisk
echo 'CHROOT:' >> ex2.txt

sudo chroot lofsdisk ./ex2 >> ex2.txt
