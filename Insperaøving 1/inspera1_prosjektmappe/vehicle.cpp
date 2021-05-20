#include "vehicle.h"

// Implement all the necessary functions as described in the task here.

Vehicle::Vehicle(string name, Color col, double speed): name{name}, col{col}, speed{speed}{};

bool Vehicle::allowedSpeed(double speed){
    if(speed < 1000){
        return true;
    }
    else{
        return false;
    }
}

Car::Car(int numberOfWheels, string name, Color col, double speed): numberOfWheels{numberOfWheels}{};

bool Car::allowedSpeed(double speed){
    if(speed < 100){
        return true;
    }
    else{
        return false;
    }
}