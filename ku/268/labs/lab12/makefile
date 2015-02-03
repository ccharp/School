Tree : main.o TNode.o bsTree.o 
	g++  main.o TNode.o bsTree.o -o Tree
main.o   : main.cpp
	g++ -c main.cpp 	
MyDlist.o: bsTree.h bsTree.cpp
	g++ -c bsTree.cpp
DNode.o : TNode.h TNode.cpp
	g++ -c TNode.cpp 
clean :
	rm *.o
