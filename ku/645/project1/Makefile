mippsSimulator: main.o Pipeline.o
	g++ -std=c++0x -g main.o Pipeline.o -o main 
main.o: main.cpp
	g++ -std=c++0x -c -g main.cpp
Pipeline.o: Pipeline.hpp Pipeline.cpp
	g++ -std=c++0x -c -g Pipeline.hpp Pipeline.cpp 
clean: rm *.o
