#include "vector.h"

void vecReplace(vector<string> &vec, string old, string replacement){
    for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++){
        if(*it == old){
            it = vec.erase(it);
            it = vec.insert(it,replacement);
        }
    }
}