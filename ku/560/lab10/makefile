something: main.o BinomialQueue.o LeftistHeap.o SkewHeap.o
	g++ -g main.o BinomialQueue.o LeftistHeap.o SkewHeap.o -o lab10
main.o: main.cpp
	g++ -c -g main.cpp 	 
LeftistHeap.o: LeftistHeap.h LeftistHeap.cpp 
	g++ -c -g LeftistHeap.cpp LeftistHeap.h
SkewHeap.o: SkewHeap.h SkewHeap.cpp 
	g++ -c -g SkewHeap.cpp SkewHeap.h
BinomialQueue.o: BinomialQueue.cpp
	g++ -c -g BinomialQueue.cpp BNode.h 
#Timer.o: Timer.
#	g++ -c Timer.h
#experiment.o: experiment.h
#	g++ -c experiment.h
clean :
	rm *.o 
