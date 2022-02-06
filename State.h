
#ifndef STATE_H
#define STATE_H

#include <string> 
#include <vector>
using namespace std;


class State {      
    public:             
        State(vector<string>);
    private: 
        int num;        
        bool start; 
        bool accept; 
        bool reject; 
};
#endif