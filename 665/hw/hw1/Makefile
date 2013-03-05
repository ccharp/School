converter: main.o Nfa.o
	g++ -std=c++11 -g main.o Nfa.o -o hw1
main.o: main.cpp
	g++ -std=c++11 -c -g main.cpp
Nfa.o: Nfa.h Nfa.cpp
	g++ -std=c++11 -c -g Nfa.cpp Nfa.h
clean: rm *.o
