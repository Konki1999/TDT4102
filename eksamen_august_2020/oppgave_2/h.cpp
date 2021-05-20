#include "h.h"

void dynamicFunc(int n){
    int* p1 = new int{n};
    int* p2 = new int[n];
    for(int i = 0; i < n; i++){
        p2[i] = n;
    }
    delete p1;
    delete[] p2;
}