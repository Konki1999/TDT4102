#pragma once
#include "std_lib_facilities.h"
#include "Graph.h"

class Animal{
protected:
    string name;
    int age;
public:
    Animal(string n, int a);
    virtual string toString() = 0;
};

class Cat : public Animal{
public:
    Cat(string n, int a) : Animal::Animal(n, a){};
    string toString();
};

class Dog : public Animal{
public:
    Dog(string n, int a) : Animal::Animal(n, a){};
    string toString();
};

void testAnimal();