//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'
double devideFunc(int a, int b){
	return static_cast<double>(a)/b;
}
// C++ programs start by executing the function main
int main()
{
	map<string,string> people {{"Ola", "Nordmann"},
						   {"Kari", "Nordmann"},
						   {"Lisa", "Andersen"}};

	people.insert({"Ola", "Andersen"});
	for (auto i : people){
		cout << i.first << " " << i.second << endl;
	};

	cout << devideFunc(5,3);

	keep_window_open();
}

//------------------------------------------------------------------------------
