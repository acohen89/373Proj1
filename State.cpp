#include "State.h"

State::State(vector<string> stateInput){
    num = stoi(stateInput.at(1));
    if(stateInput.at(2) == "start"){
        start = true; 
        accept = false; 
        reject = false; 
    } else if (stateInput.at(2) == "accept" ){
        accept = true;
        start = false;
        reject = false;
    } else if (stateInput.at(2) == "reject"){
        reject = true; 
        accept = false;
        start = false; 
    }
}
