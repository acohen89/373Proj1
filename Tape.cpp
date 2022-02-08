#include "Tape.h"

Tape::Tape(string init){
    tape = init; 
}

ostream& operator<<(ostream& os, const Tape& t){
    os << "Tape " << t.tape << " Head Index: " << t.headIndex << " Head Char " <<  t.headChar; 
    return os;
}
