#include "Tape.h"

Tape::Tape(string init){
    tape = init; 
    headIndex = 0;
    headChar = init[0];
}

ostream& operator<<(ostream& os, const Tape& t){
    os << "Tape " << t.tape << " Head Index: " << t.headIndex << " Head Char " <<  t.headChar; 
    return os;
}
