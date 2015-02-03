prog1: DNode.o MyDList.o main.o
	g++ DNode.o MyDList.o main.o -o dllist
DNode.o: DNode.cpp DNode.h
	g++ -c DNode.cpp  
MyDList.o: MyDList.cpp MyDlist.h
	g++ -c MyDList.cpp 
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o
