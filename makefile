bst: clean main.o 
	g++ -o bst main.o 
main.o: main.cpp Binary_tree.h Search_tree.h errorcode.h
	g++ -c -g -Wall -std=c++11 main.cpp
clean:
	rm -f *.o bst
