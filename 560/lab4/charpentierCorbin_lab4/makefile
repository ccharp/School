lab4 : main.o BinarySearchTree.o 
	g++  main.o BinarySearchTree.o -o lab4
main.o   : main.cpp
	g++ -c main.cpp 	 
BinarySearchTree.o: BinarySearchTree.h BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp TNode.h 
#Timer.o: Timer.h
#	g++ -c Timer.h
#experiment.o: experiment.h
#	g++ -c experiment.h
clean :
	rm *.o 

