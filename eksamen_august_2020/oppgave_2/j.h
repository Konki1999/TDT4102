#pragma once

#include <iostream>

using namespace std;


class Base{
private:
    int num;
public:
    Base(int n);   
};

class Derived : public Base{
private:
    string* sPtr;
public:
    Derived(int n, string* ptr = nullptr) : Base(n), sPtr{ptr} {};
};