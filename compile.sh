#!/bin/bash

flex "$1"
gcc -c lex.yy.c -lfl
gcc -c "$2"
file_name=$(echo "$2" | cut -d '.' -f 1)
gcc -o "$3" lex.yy.o "$file_name.o"
rm lex.yy.c *.o
