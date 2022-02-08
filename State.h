
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
        int getNum(){return num;}
        void addTransition(Transition);
        friend ostream& operator<<(ostream& os, const State& st);
    private: 
        int num;        
        string state; 
        vector<Transition> trans; 
};
#endif