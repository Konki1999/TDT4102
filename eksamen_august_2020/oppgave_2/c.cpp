#include "c.h"

int powerFunc(char c, int i, int j){
    int res = 0;
    switch(c){
    case 'a':
        res = pow(i,2);
        break;
    case 'b':
        res = pow(i,3);
        break;
    case 'c':
        res = pow(i,j);
        break;
    default:
        res = 2;
    }
    return res;
}