
#ifndef STATE_H
#define STATE_H

#include <string> 
#include <vector>
#include <iostream>
using namespace std;


class State {      
    public:             
        State(vector<string>);
        friend ostream& operator<<(ostream& os, const State& st);
    private: 
        int num;        
        string state; 
};
#endif