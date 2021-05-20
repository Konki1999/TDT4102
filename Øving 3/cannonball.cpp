#include "std_lib_facilities.h"
#include "cannonball.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "utilities.h"

double pi = atan(1)*4;

double acclY(){
    return -9.81;
}
double velY(double initVelocityY, double time){
    double a = acclY();
    return initVelocityY + a*time;
}
double posX(double initPositionX, double initVelocityX, double time){
    return initPositionX + initVelocityX*time;
}
double posY(double initPositionY, double initVelocityY, double time){
    double v = velY(initVelocityY, time);
    double a = acclY();
    return initPositionY + (pow(v,2)-pow(initVelocityY,2))/(2*a);
}
void printTime(double time){
    cout << "Kulen brukte " << fixed << setprecision(2) << time << "s\n";
}

double flightTime(double initVelocityY, double initPositionY){
    double a = acclY();
    double timeToTop = -initVelocityY/a;
    double distanceToTop = initVelocityY * timeToTop + 1/2.*a*pow(timeToTop,2);
    double timeToBottom = sqrt(2*(-distanceToTop+initPositionY)/a);
    return timeToTop + timeToBottom;
}

double getUserInputTheta(){
    double theta;
    cout << "Skriv inn en vinkel fra underlaget i grader: ";
    cin >> theta;
    return degToRad(theta);
}

double getUserInputAbsVelocity(){
    double absVel;
    cout << "Skriv inn absoluttveriden av hastigheten: ";
    cin >> absVel;
    return absVel;
}

double getUserInputInitPosX(){
    double posX;
    cout << "Skriv inn kanonens x-posisjon: ";
    cin >> posX;
    return posX;
}

double getUserInputInitPosY(){
    double posY;
    cout << "Skriv inn kanonens y-posisjon: ";
    cin >> posY;
    return posY;
}

double degToRad(double deg){
    return deg/360.*2*pi;
}

double getVelocityY(double theta, double absVelocity){
    return absVelocity*sin(theta);
}

double getVelocityX(double theta, double absVelocity){
    return absVelocity*cos(theta);
}

vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> vel;
    double xVel = getVelocityX(theta, absVelocity);
    double yVel = getVelocityY(theta, absVelocity);
    vel.push_back(xVel);
    vel.push_back(yVel);
    return vel;
}

double getDistanceTraveled(double velocityX, double velocityY, double initPosX, double initPosY){
    double time = flightTime(velocityY, initPosY);
    printTime(time);
    return posX(initPosX, velocityX, time);
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY, double initPosX, double initPosY){
    return getDistanceTraveled(velocityX, velocityY, initPosX, initPosY) - distanceToTarget;
}

bool targetHit(double distance, double maxError){
    return abs(distance) < maxError;
}

void playTargetPractice(){
    double x = getUserInputInitPosX();
    double y = getUserInputInitPosY();
    double disToTar = randomWithLimits(100,1000);
    bool hit = false;
    for(int i = 0; i<10; i++){
        double v = getUserInputAbsVelocity();
        double theta = getUserInputTheta();
        vector<double> vel = getVelocityVector(theta,v);
        double hitFromTarget = targetPractice(disToTar, vel[0], vel[1], x, y);
        hit = targetHit(hitFromTarget,5);
        if(hit){
            cout << "Gratulerer, du vant!\n";
            break;
        }
        else if(hitFromTarget < 0){
            cout << "Du traff " << abs(hitFromTarget) << "m foran blinken.\n";
        }
        else{
            cout << "Du traff " << abs(hitFromTarget) << "m bak blinken.\n";
        }
    }
    if(!(hit)){
        cout << "Beklager, du tapte.\n";
    }
}