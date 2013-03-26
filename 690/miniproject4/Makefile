MAIN: main.o 
	g++ -std=c++11 -g main.o -o main
main.o: main.cpp viginere.cpp Timer.h
	g++ -std=c++11 -c -g main.cpp viginere.cpp Timer.h

clean:
		rm *.o *.swp *~
