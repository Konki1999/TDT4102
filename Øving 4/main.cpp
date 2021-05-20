//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "mastermind.h"
#include <ctime>
#include <cmath>
#include <cstdlib>

//------------------------------------------------------------------------------'
void menu(){
	int choice = 0;
	bool run = true;
	while(run){
		cout << "Please choose an option\n";
		cout << "00) Exit\n"
		 	 << "01) Test incrementByValueNumTimes\n"
			 << "02) Test incrementByValueNumTimesRef\n"
			 << "03) Test swap\n"
			 << "04) Test toLower\n"
			 << "05) Test Student\n"
			 << "06) Test string\n"
			 << "07) Test inputToString\n"
			 << "08) Test countChar\n"
			 << "09) Play Mastermind :)\n"
			 << "10) Play Mastermind visually\n";
		cin >> choice;
		switch(choice){
			case 0:
				run = false;
				break;
			case 1:
				testCallByValue();
				cout << endl;
				break;
			case 2:
				testCallByReference();
				cout << endl;
				break;
			case 3:
				testSwap();
				cout << endl;
				break;
			case 4:
				testToLower();
				cout << endl;
				break;
			case 5:
				testStudent();
				cout << endl;
				break;
			case 6:
				testString();
				cout << endl;
				break;
			case 7:
				testReadToString();
				cout << endl;
				break;
			case 8:
				testCountChar();
				cout << endl;
				break;
			case 9:
				playMastermind();
				cout << endl;
				break;
			case 10:
				playMastermindVisual();
				cout << endl;
				break;
			default:
				break;
		}
	}
}

// C++ programs start by executing the function main
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	menu();
}

//------------------------------------------------------------------------------
