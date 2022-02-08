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
void State::addTransition(Transition t){
    if(t.getStartState() == num){
        trans.push_back(t); 
    } else {cout << "Bad transition " << endl;}
}
ostream& operator<<(ostream& os, const State& st){
    os << "Num: " << st.num << " State: " << st.state << endl;
    for(int t = 0; t < st.trans.size(); t++){
        os << "    ";
        os << st.trans.at(t) << endl; 
    }

    return os;
}
