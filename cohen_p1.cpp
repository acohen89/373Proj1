#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdbool.h>
#include <bits/stdc++.h>

#include "State.h"
#include "Transition.h"
using namespace std; 


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

bool readText(string fileName){
    string line; 
    ifstream file (fileName);
    if (file.is_open()){
        while ( getline (file, line) ){
            vector<string> lineVector = stringToVector(line);
            if(lineVector.at(0) == "state"){
                State s(lineVector);
                cout << s << endl; 
            } else if(lineVector.at(0) == "transition"){
                Transition t(lineVector);
                cout << t << endl;
            } else {
                cout << "Error on reading input file " << endl; 
            }
        }
        file.close();
        return true; 
    } else return false; 
}
int main(int argc, char *argv[]){
    cout << "Hello World" << endl; 
    if(!readText(argv[1])) cout << "input file reading error" << endl; 
    return 0; 
}

