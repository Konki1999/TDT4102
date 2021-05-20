#pragma once

#include <iostream>
using namespace std;

class Student{
    string name;
    int studNr;
public:
    Student(string name, int studNr) : name{name}, studNr{studNr} {};
    friend ostream & operator<<(ostream & os, Student s);
};