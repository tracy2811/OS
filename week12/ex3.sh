#!/bin/bash
for i in 1 100
do
	dd if=/dev/zero of=file$i bs=1M count=$i
done

for k in 32 1024
do
	echo "--------------------" >> ex3.txt
	echo "BUF_SIZE = $k bytes" >> ex3.txt
	gcc copy.c -o copy -DBUF_SIZE=$k
	gcc copy.c -o copy1 -DBUF_SIZE=$k -DSYNC=1

	for i in 1 100
	do
		echo "----File size = $i M" >> ex3.txt
		echo "--No O_SYNC" >> ex3.txt
		{ time ./copy file$i fileB ; } >> ex3.txt 2>&1
		echo "--O_SYNC" >> ex3.txt
		{ time ./copy1 file$i fileB ; } >> ex3.txt 2>&1
	done
done

rm copy copy1 file{1,100} fileB
