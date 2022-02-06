#include "Transition.h"
#include <iostream> 

Transition::Transition(vector<string> line){
  if(line.size() == 6){
    currentState = stoi(line.at(1));
    inputSymbol = line.at(2)[0];
    nextState = stoi(line.at(3));
    writeToTape = line.at(3)[0];
    direction = line.at(4)[0]; 
  }
}

ostream& operator<<(ostream& os, const Transition& tr){
    os << "Current State: " << tr.currentState << " Input Symbol: " << tr.inputSymbol << " Next State: " << tr.nextState << " Write To Tape: " << tr.writeToTape << " Direction: " << tr.direction; 
    return os;
}