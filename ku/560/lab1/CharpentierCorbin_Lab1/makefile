lab1 : main.o List.o Node.o Array.o 
	g++  main.o List.o Node.o Array.o -o lab1
main.o   : main.cpp
	g++ -c main.cpp 	
List.o: List.h List.cpp
	g++ -c List.cpp
Node.o : Node.h Node.cpp
	g++ -c Node.cpp 
Array.o: Array.h Array.cpp
	g++ -c Array.cpp
clean :
	rm *.o 

