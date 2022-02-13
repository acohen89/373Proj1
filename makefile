CC = g++ -O -o

c: cohen_p1.o State.o Transition.o Tape.o
	clear
	g++ -g -O0 -o cohen_p1 cohen_p1.o State.o Transition.o Tape.o

cohen_p1: cohen_p1.o State.o Transition.o Tape.o
	g++ -g -O0 -o cohen_p1 cohen_p1.o State.o Transition.o Tape.o

State.o: State.cpp
	g++ -g -O0 -c State.cpp

Transition.o: Transition.cpp
	g++ -g -O0 -c Transition.cpp

cohen_p1.o: cohen_p1.cpp
	g++ -g -O0 -c cohen_p1.cpp

Tape.o: Tape.cpp
	g++ -g -O0 -c Tape.cpp


clean: 
	rm -f core *.o 
	rm cohen_p1

	
cleanc: 
	rm -f core *.o 
	rm cohen_p1
	clear

