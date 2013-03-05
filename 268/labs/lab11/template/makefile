dlist : main.o MyDlist.o DNode.o 
	g++  main.o MyDlist.o DNode.o -o dlist
main.o   : main.cpp
	g++ -c main.cpp 	
MyDlist.o: MyDlist.h MyDlist.cpp
	g++ -c MyDlist.cpp
DNode.o : DNode.h DNode.cpp
	g++ -c DNode.cpp 
clean :
	rm *.o
