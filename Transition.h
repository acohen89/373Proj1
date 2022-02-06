#ifndef TRANSITION_H
#define TRANSITION_H

#include <string> 
#include <vector>
using namespace std;

class Transition {   
  private:            
    int currentState; 
    char inputSymbol;
    int nextState; 
    char writeToTape; 
    char direction; 
  public: 
    Transition(vector<string>);
      friend ostream& operator<<(ostream& os, const Transition& tr);

};

#endif