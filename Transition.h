#ifndef TRANSITION_H
#define TRANSITION_H

#include <string> 
#include <vector>
#include <iostream>
using namespace std;

class Transition {   
  private:            
    int startState; 
    char inputSymbol; // transition only taken if tapehead points to this symbol 
    int nextState; 
    char writeToTape; 
    char direction; 
  public: 
    Transition(vector<string>);
    Transition(){};
    int getStartState();
    int getNextState(){return nextState;}
    char getWriteToTape(){return writeToTape;}
    char getInputSymbol(){return inputSymbol;}
    char getDirection(){return direction;}
    friend ostream& operator<<(ostream& os, const Transition& tr);

};

#endif