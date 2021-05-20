//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------'
//a)
double maxOfTwo(double a, double b){
	if(a > b){
		cout << "A is greater than B\n";
		return a;
	}
	else{
		cout << "B is greater than A\n";
		return b;
	}
}

//c)
int fibonacci(int n){
	int a = 0;
	int b = 1;
	cout << "Fibonacci number:\n";
	for(int x = 1; x < n+1; x++){
		cout << x << ' ' << b << '\n';
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "----\n";
	return b;
}

//d)
int squareNumbers(int n){
	int totalSum = 0;
	for(int i = 0; i < n; i++){
		totalSum += i*i;
		cout << i*i << '\n';
	}
	cout << totalSum << '\n';
	return totalSum;
}

//e)
int triangleNumbersBelow(int n){
	int acc = 1;
	int num = 2;
	cout << "Triangle numbers below " << n << ":\n";
	while(acc<n){
		cout << acc << '\n';
		acc += num;
		num++;
	}
	return num;
}

//f)
bool isPrime(int n){
	for(int j = 2; j < n; j++){
		if(n%j == 0){
			return false;
		}
	}
	return true;
}

//g)
void naivePrimeNumberSearch(int n){
	for(int number = 2; number < n; number++){
		if(isPrime(number)){
			cout << number << " is a prime\n";
		}
	}
}

//h)
int findGreatestDivisor(int n){
	for(int divisor = n-1; divisor > 0; divisor -= 1){
		if(n%divisor == 0){
			return divisor;
		}
	}
}

//b)
int main()
{
	cout << "Oppgave a)\n";
	cout << maxOfTwo(5,6) << '\n';

	cout << "Oppgave c)\n";
	cout << fibonacci(15) << '\n';

	cout << "Oppgave d)\n";
	cout << squareNumbers(5) << '\n';

	cout << "Oppgave e)\n";
	triangleNumbersBelow(10);

	cout << "Oppgave f)\n";
	cout << isPrime(5) << '\n';
	cout << isPrime(6) << '\n';

	cout << "Oppgave g)\n";
	naivePrimeNumberSearch(11);

	cout << "Oppgave h)\n";
	cout << findGreatestDivisor(10) << '\n';

	keep_window_open();
}
//------------------------------------------------------------------------------
