
#ifndef STATE_H
#define STATE_H

#include <string> 
#include <vector>
#include <iostream>
#include "Transition.h"
using namespace std;


class State {      
    public:             
        State(vector<string>);
        State();
        int getNum(){return num;}
        string getState(){return state;}
        void addTransition(Transition);
        Transition findTrans(char);
        friend ostream& operator<<(ostream& os, const State& st);
    private: 
        int num;        
        string state; 
        vector<Transition> trans; 
};
#endif