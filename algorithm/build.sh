#!/bin/bash

if [ $# -ne 1 ]
then
	echo "Invalid parameter"
	exit
fi

bin_path="./bin"
if [ ! -d $bin_path ]; then
	mkdir $bin_path
fi

src_file=$1
dst_file=$bin_path/$(basename $src_file .cpp)

# compile source file
if test -f $src_file
then
	g++ -g -std=c++11 $src_file -o $dst_file
else
	echo "$src_file NOT FOUND"
	exit
fi
 
# run bin
if test -f $dst_file
then
	echo "run $dst_file"
	$dst_file
fi

