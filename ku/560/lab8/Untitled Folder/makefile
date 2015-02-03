lab4 : main.o LeftistHeap.o SkewHeap.o
	g++  main.o LeftistHeap.o SkewHeap.o -o lab8 
main.o   : main.cpp
	g++ -c main.cpp 	 
LeftistHeap.o: LeftistHeap.h LeftistHeap.cpp
	g++ -c LeftistHeap.cpp  
SkewHeap.o: SkewHeap.h SkewHeap.cpp LeftistHeap.h
	g++ -c SkewHeap.cpp
#Timer.o: Timer.
#	g++ -c Timer.h
#experiment.o: experiment.h
#	g++ -c experiment.h
clean :
	rm *.o 

