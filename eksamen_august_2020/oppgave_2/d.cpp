#include "d.h"

void testStringPtr(){
    string s = "Hei";
    string* sPtr = &s;
    *sPtr+="Hallo";
    cout << s << endl;
}