#pragma once
#include "Car.h"
#include <ostream>

class Person{
private:
    string name;
    string email;
    Car* car;
public:
    Person(string name, string email, Car* car = nullptr);
    string getName() const;
    string getEmail() const;
    void setEmail(string email_address); 
    bool hasAvailableSeats() const;
    friend ostream& operator<<(ostream& os, const Person& p);
};

void testPerson();