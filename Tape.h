#ifndef TAPE_H
#define TAPE_H

#include <string> 
#include <vector>
#include <iostream>


using namespace std;

class Tape{   
  public: 
    string tape;   
    int headIndex;
    char headChar;         
    Tape(string);
    friend ostream& operator<<(ostream& os, const Tape& t);

};

#endif