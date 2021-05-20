#pragma once
#include <iostream>

using namespace std;

class Dummy{
public:
    int* num;
    Dummy() {
        num =new int{0};
    }
    ~Dummy() {
        delete num;
    }
    Dummy(const Dummy& d);
    Dummy operator=(const Dummy& d);
};

void dummyTest();