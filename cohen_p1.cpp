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
            // cout << "Added Transition " << t << " to State " << s->at(i) << endl; 
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
        // cout << word << endl;
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
                // cout << t << endl;
            } else {
                cout << "Error on reading input file " << endl; 
            }
        }
        file.close();
        return true; 
    } else return false; 
}

int main(int argc, char *argv[]){
    //TODO: create tapehead 
    //* initial tape = argv[2]
    //* max num of transistions = argv[3]
    //* loop through this 
    //*initialize current state to start state 
    //* current chracter the tape head is at / what posistion 
    //* tape contents 
    Tape tape(argv[2]);
    cout << tape << endl;
    vector<State> *states = new vector<State>;
    cout << "Hello World" << endl; 
    if(!readText(argv[1], states)) cout << "input file reading error" << endl; 
    for(int s = 0; s < states->size(); s++){
        cout << states->at(s) << endl;
    }
    return 0; 
}

