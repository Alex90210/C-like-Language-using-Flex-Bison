#!/bin/bash

rm -f lex.yy.c
rm -f limbaj.tab.c
rm -f limbaj
bison -d -Wcounterexamples limbaj.y 
flex limbaj.l
g++ utils.cpp AST.h lex.yy.c limbaj.tab.c -std=c++11 -o limbaj
./limbaj test.txt
