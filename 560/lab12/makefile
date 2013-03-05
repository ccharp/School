something: main.o EdgeArray.o DisjointSets.o Matrix.o
	g++ -g main.o EdgeArray.o DisjointSets.o Matrix.o -o lab12
main.o: main.cpp
	g++ -c -g main.cpp  
EdgeArray.o: EdgeArray.h EdgeArray.cpp 
	g++ -c -g EdgeArray.cpp EdgeArray.h Edge.h
DisjointSets.o: DisjointSets.h DisjointSets.cpp 
	g++ -c -g DisjointSets.cpp DisjointSets.h
Matrix.o: Matrix.cpp Matrix.h
	g++ -c -g Matrix.cpp Matrix.h
#Timer.o: Timer.
#	g++ -c Timer.h
#experiment.o: experiment.h
#	g++ -c experiment.h
clean :
	rm *.o 
