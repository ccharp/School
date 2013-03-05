prog1: MyStack.o main.o
	g++ MyStack.o main.o -o main
MyStack.o: MyStack.cpp MyStack.h
	g++ -c DNode.cpp  
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm *.o
