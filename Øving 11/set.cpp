#include "set.h"

void setReplace(set<string> &s, string old, string replacement){
    for(set<string>::iterator it = s.begin(); it != s.end(); it++){
        if(*it == old){
            it = s.erase(it);
            it = s.insert(it,replacement);
        }
    }
}