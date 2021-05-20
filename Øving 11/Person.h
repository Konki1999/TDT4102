#pragma once

#include <iostream>
#include <list>

using namespace std;

class Person{
private:
    string fName;
    string sName;
public:
    Person(string fName, string sName);

    void setFName(string name);
    void setSName(string name);
    string getFName() const;
    string getSName() const;

    friend ostream& operator<<(ostream &os, Person &p);

};

void insertOrdered(list<Person> &l, const Person& p);