#/bin/sh

clang++ $1 -std=c++11 -o .execute.out

mkdir "out$2"

for var in {1..5}
	do
		input_file=`ls *in$2/*$var.txt`
		output_file="out$2/out$var.txt"
		./.execute.out < $input_file > $output_file
	done
