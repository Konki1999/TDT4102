//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "tests.h"
#include "blackjack.h"

//------------------------------------------------------------------------------'
void menu(){
	int choice = 0;
	bool run = true;
	while(run){
		cout << "Please select an option\n"
			<< "00) Exit\n"
			<< "01) Test Card class\n"
			<< "02) Test CardDeck class\n"
			<< "03) Play Blackjack\n";
		cin >> choice;
		switch(choice){
			case 0:
				run = false;
				break;
			case 1:
				testCard();
				break;
			case 2:
				testCardDeck();
				break;
			case 3:
				playBlackjack();
			default:
				break;
		}
	}
}


// C++ programs start by executing the function main
int main()
{
	srand(time(0));
	menu();
}

//------------------------------------------------------------------------------
