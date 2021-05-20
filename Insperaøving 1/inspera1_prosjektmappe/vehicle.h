#pragma once
#include "std_lib_facilities.h"

// Task a)
// Create an color enum here
enum class Color{blue, red, green, yellow, purple, brown, gold, silver, grey, black};

// Task b) 
// Complete the Vehicle class as described in the task
class Vehicle {
private:
    string name;
public:
    Vehicle(string name, Color col, double speed);
    Color col;
    double speed;
    bool allowedSpeed(double speed);
};


// Task c)
// Create the Car class underneath as described in the task

class Car : public Vehicle{
private:
    int numberOfWheels;
public:
    Car(int numberOfWheels, string name, Color col, double speed) : Vehicle(name, col, speed);
    void changeColor(Color newColor);
    bool allowedSpeed(double speed);
}
