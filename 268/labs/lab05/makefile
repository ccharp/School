prog1: DNode.o main.o
	g++ DNode.o main.o -o main
DNode.o: DNode.cpp DNode.h
	g++ -c DNode.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o
