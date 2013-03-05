prog5 : main.o MyList.o Node.o 
	g++  main.o MyList.o Node.o -o prog5
main.o   : main.cpp
	g++ -c main.cpp 	
MyList.o: MyList.h MyList.cpp
	g++ -c MyList.cpp
Node.o : Node.h Node.cpp
	g++ -c Node.cpp 
clean :
	rm *.o 
