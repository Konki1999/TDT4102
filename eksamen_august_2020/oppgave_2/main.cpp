#include "b.h"
#include "c.h"
#include "d.h"
#include "g.h"

namespace First{
	int a;
};

namespace Second{
	int a;
};

int main(){
	int* ptr = &First::a;
	*ptr = 5;

	ptr = &Second::a;
	*ptr = 6;

	cout << "First: " << First::a << endl;
	cout << "Second: " << Second::a << endl;
	cout << "----------------------------\n";

	Student s1("Anakin",123456);
	cout << s1;

	cout << "----------------------------\n";
	
	int balle = powerFunc();
	cout << balle << endl;
	
	cout << "----------------------------\n";

	testStringPtr();

	cout << "----------------------------\n";

	insertLineNumbers("test.txt");
}