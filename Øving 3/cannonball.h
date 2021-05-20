#pragma once

double acclY();
double velY(double initVelocityY, double time);
double posX(double initPositionX, double initVelocityX, double time);
double posY(double initPositionY, double initVelocityY, double time);
void printTime(double time);
double flightTime(double initVelocityY, double initPositionY);
double getUserInputTheta();
double getUserInputAbsVelocity();
double getUserInputInitPosX();
double getUserInputInitPosY();
double degToRad(double deg);
double getVelocityY(double theta, double absVelocity);
double getVelocityX(double theta, double absVelocity);
vector<double> getVelocityVector(double theta, double absVelocity);
double getDistanceTraveled(double velocityX, double velocityY, double initPosX, double initPosY);
double targetPractice(double distanceToTarget, double velocityX, double velocityY, double initPosX, double initPosY);
bool targetHit(double distance, double maxError);
void playTargetPractice();