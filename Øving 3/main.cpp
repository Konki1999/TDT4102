//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <ctime>

//------------------------------------------------------------------------------'

void testDeviation(double compareOperand,double toOperand,double maxError, string name);

// C++ programs start by executing the function main
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	cout << velY(25.0,2.5) << '\n';
	cout << posX(0.,50.,5) << '\n';
	cout << posY(0.,25.,2.5) << '\n';

	testDeviation(posX(0.,50.,5.),249,1.,"posX(0.,50.,5.)");

	for(int i = 0; i<10; i++){
		cout << randomWithLimits(5,15) << '\n';
	}

	cout << "--- Nå skyter vi med kanon! ---\n";
	playTargetPractice();

	keep_window_open();
}

//------------------------------------------------------------------------------

void testDeviation(double compareOperand,double toOperand,double maxError, string name){
	double err = abs(compareOperand-toOperand);
	cout << name << '\n';
	if(err <= maxError){
		cout << "Verdiene er tilnaermet like.\n";
	}
	else{
		cout << "Verdiene er IKKE tilnaermet like.\n";
	}
}

