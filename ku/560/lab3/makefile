lab3 : main.o List.o Node.o Array.o 
	g++  main.o List.o Node.o Array.o -o lab3
main.o   : main.cpp
	g++ -c main.cpp Timer.h experiment.h	
List.o: List.h List.cpp
	g++ -c List.cpp
Node.o : Node.h Node.cpp
	g++ -c Node.cpp 
Array.o: Array.h Array.cpp
	g++ -c Array.cpp
#Timer.o: Timer.h
#	g++ -c Timer.h
#experiment.o: experiment.h
#	g++ -c experiment.h
clean :
	rm *.o 

