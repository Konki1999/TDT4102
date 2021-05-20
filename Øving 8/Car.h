#pragma once
#include "std_lib_facilities.h"

class Car{
private:
    int freeSeats;
public:
    Car(int seats) : freeSeats{seats}{};
    bool hasFreeSeats() const;
    void reserveFreeSeat();
}; 