lab5 : main.o BinaryHeap.o 
	g++  main.o BinaryHeap.o -o lab5
main.o   : main.cpp
	g++ -c main.cpp 	 
BinarySearchTree.o: BinaryHeap.h BinaryHeap.cpp
	g++ -c BinaryHeap.cpp TNode.h 
#Timer.o: Timer.h
#	g++ -c Timer.h
#experiment.o: experiment.h
#	g++ -c experiment.h
clean :
	rm *.o 

