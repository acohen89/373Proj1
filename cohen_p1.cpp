#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdbool.h>
#include <bits/stdc++.h>

#include "Tape.h"
#include "State.h"
#include "Transition.h"
using namespace std; 


void addTransition(Transition t, vector<State> *s){
    for(int i = 0; i < s->size(); i++){
        if(t.getStartState() == s->at(i).getNum()){
            s->at(i).addTransition(t); 
        }
    }
}


vector<string> stringToVector(string s)
{
    stringstream ss(s);
    string word;
    vector<string> stringVect; 
    while (ss >> word) {
        stringVect.push_back(word);
    }
    return stringVect;
}

bool readText(string fileName, vector<State> *states){
    string line; 
    ifstream file (fileName);
    if (file.is_open()){
        while ( getline (file, line) ){
            vector<string> lineVector = stringToVector(line);
            if(lineVector.at(0) == "state"){
                State s(lineVector);
                states->push_back(s);
            } else if(lineVector.at(0) == "transition"){
                Transition t(lineVector);
                addTransition(t, states);
            } else {
                cout << "Error on reading input file " << endl; 
            }
        }
        file.close();
        return true; 
    } else return false; 
}

State findStartState(vector<State> *states){
    for(int s = 0; s < states->size(); s++){
        if(states->at(s).getState() == "start"){
            return states->at(s);
        }
    }   
    return State(); 
}

State findState(int desiredState, vector<State> *states){
    for(int s = 0; s < states->size(); s++){
        if(states->at(s).getNum() == desiredState){
            return states->at(s); 
        }
    }
    return State(); 
}

string parseOutput(string out, int tapeIndex){
    string ret  = "";
    for(int s = tapeIndex; s < out.size(); s++){
        if(tapeIndex >= out.size()){
            return out; 
        } else{
            if(out[s] != '_'){
                ret += out[s];
            } else {
                return ret; 
            }
        }
    }
    return ret; 

}
string runMachine(vector<State> *states, Tape tape, int maxIters){
    State cState = findStartState(states); 
    for(int i = 0; i < maxIters; i++){ //* Starts having blank transitions after i = 4
        if(cState.getState() == "accept" || cState.getState() == "reject"){
            return parseOutput(tape.tape, tape.headIndex) + " " + cState.getState(); 
        } 

        Transition curTran = cState.findTrans(tape.headChar); //* Seg Fault
        tape.tape[tape.headIndex] = curTran.getWriteToTape();
        if(curTran.getDirection() == 'R'){
            tape.headIndex++;
            if(tape.headIndex >= tape.tape.size()){
                tape.tape += '_'; 
            }
        } else if(curTran.getDirection() == 'L'){
            if(tape.headIndex - 1 < 0){
                tape.headIndex = 0;
                tape.tape = "_" + tape.tape;  
            } else {
                tape.headIndex--;
            }
        }      
        tape.headChar = tape.tape[tape.headIndex]; 

        cState = findState(curTran.getNextState(), states);
        cout << "Out " << tape.tape << endl << endl;

    }
    return parseOutput(tape.tape, tape.headIndex) + " " + "quit";

}

int main(int argc, char *argv[]){
    Tape tape(argv[2]);
    vector<State> *states = new vector<State>;
    if(!readText(argv[1], states)) cout << "input file reading error" << endl; 
    cout << runMachine(states, tape, stoi(argv[3])) << endl; 
    return 0; 
}

