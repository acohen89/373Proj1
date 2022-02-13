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

State::State(){}

Transition State::findTrans(char inputSymbol){ 
    cout << "Looking for transition with inputSymbol " << inputSymbol << " in state "  << num << endl; 
    for(int t = 0; t < trans.size(); t++){
        // cout << t << endl;
        // cout << trans.at(t) << endl;
        if(trans.at(t).getInputSymbol() == inputSymbol){
            return trans.at(t);
        }
    }
    //* error comes from not finding the input symbol I think 
    return Transition(); 
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
