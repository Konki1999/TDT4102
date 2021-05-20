//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

//------------------------------------------------------------------------------'
#include "textProcessing.h"
#include "CourseCatalog.h"
#include "Temps.h"

// C++ programs start by executing the function main
int main()
{
	writeToFile("writeFile.txt");
	readFromFile("writeFile.txt");
	auto charCountVec = charCountInFile("grunnlov.txt",'z');
	for(char x = 'a'; x <= 'z'; x++){
		cout << x << ": " << charCountVec[x - 'a'] << endl;
	}

	testCourses();

	testTemps();

	keep_window_open();
}

//------------------------------------------------------------------------------
