lab4 : main.o BinarySearchTree.o BinaryHeap.o
	g++ -g main.o BinarySearchTree.o BinaryHeap.o -o lab6
main.o: main.cpp
	g++ -c -g main.cpp 	 
BinaryHeap.o: BinaryHeap.h BinaryHeap.cpp
	g++ -c -g BinaryHeap.h BinaryHeap.cpp
BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -c -g BinarySearchTree.cpp TNode.h 
Timer.o: Timer.h
	g++ -c Timer.h
experiment.o: experiment.h
	g++ -c -g experiment.h
clean :
	rm *.o 

