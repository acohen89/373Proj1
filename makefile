CC = g++ -O -o



cohen_p1: cohen_p1.o State.o Transition.o
	g++ -g -O -o cohen_p1 cohen_p1.o State.o Transition.o

State.o: State.cpp
	g++ -g -O -c State.cpp

Transition.o: Transition.cpp
	g++ -g -O -c Transition.cpp

cohen_p1.o: cohen_p1.cpp
	g++ -g -O -c cohen_p1.cpp

clean: 
	rm -f core *.o 
	rm cohen_p1

	
cleanc: 
	rm -f core *.o 
	rm cohen_p1
	clear

