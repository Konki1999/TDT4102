#include "b.h"

ostream & operator<<(ostream & os, Student s){
    os << "Name: " << s.name << endl << "StudNr: " << s.studNr << endl;
    return os;
}