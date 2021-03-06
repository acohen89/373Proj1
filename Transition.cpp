#include "Transition.h"
#include <iostream> 

Transition::Transition(vector<string> line){
  if(line.size() == 6){
    startState = stoi(line.at(1));
    inputSymbol = line.at(2)[0];
    nextState = stoi(line.at(3));
    writeToTape = line.at(4)[0];
    direction = line.at(5)[0]; 
  }
}

int Transition::getStartState(){
  return startState; 
}

ostream& operator<<(ostream& os, const Transition& tr){
    os << "Start State: " << tr.startState << " Input Symbol: " << tr.inputSymbol << " Next State: " << tr.nextState << " Write To Tape: " << tr.writeToTape << " Direction: " << tr.direction; 
    return os;
}