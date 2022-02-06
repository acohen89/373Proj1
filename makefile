CC = g++ -O -o



cohen_p1: cohen_p1.o State.o
	g++ -O -o cohen_p1 cohen_p1.o State.o 

State.o: State.cpp
	g++ -O -c State.cpp

cohen_p1.o: cohen_p1.cpp
	g++ -O -c cohen_p1.cpp

clean: 
	rm -f core *.o 
	rm cohen_p1
