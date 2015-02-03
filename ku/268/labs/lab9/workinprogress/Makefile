excep: main.o MyList.o node.o 
	g++  main.o MyList.o node.o -o excep
main.o: main.cpp
	g++ -c main.cpp
MyList.o: MyList.h MyList.cpp MyDListIndexOutOfRange.h
	g++ -c MyList.cpp
node.o: node.h node.cpp
	g++ -c node.cpp
clean:
	rm *.o 
