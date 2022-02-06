#include "State.h"


State::State(vector<string> stateInput){

    num = stoi(stateInput.at(1));
    if(stateInput.size() > 2){
        if(stateInput.at(2) == "start"){
            state = "start";
        } else if (stateInput.at(2) == "accept" ){
            state = "accept";
        } else if (stateInput.at(2) == "reject"){
            state = "reject";
        }
    } else {
        state = "NONE"; 
    }
}
ostream& operator<<(ostream& os, const State& st){
    os << "Num: " << st.num << " State: " << st.state; 
    return os;
}
