//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main

//1a)
void inputAndPrintInteger(){
	int x = 0;
	cout << "Skriv inn et heltall: ";
	cin >> x;
	cout << "Ditt heltall er " << x << '\n';
}

//b)
int inputInteger(){
	int x = 0;
	cout << "Skriv inn et heltall: ";
	cin >> x;
	return x;
}

//c)
void inputIntegersAndPrintSum(){
	int x = inputInteger();
	int y = inputInteger();
	cout << "Summen av dine heltall er " << x + y << '\n';
}

//d)
//inputInteger gir ut en verdi, noe inputIntegerAndPrint ikke gjør

//e)

bool isOdd(int x){
	if(x%2 != 0){
		return true;
	}
	else{
		return false;
	}
}

//f)
string printHumanReadableTime(int s){
	int yrs = 0;
	int days = 0;
	int hrs = 0;
	int mins = 0;

	while(s >= 31557600){
		yrs += 1;
		s -= 31557600;
	}
	while(s >= 86400){
		days += 1;
		s -= 86400;
	}
	while(s >= 3600){
		hrs += 1;
		s -= 3600;
	}
	while(s >= 60){
		mins += 1;
		s -= 60;
	}
	string str = to_string(yrs) + " ar, " + to_string(days) + " dager, " + to_string(hrs) + " timer, " + to_string(mins) + " minutter, og " + to_string(s) + " sekunder.\n";
	return str;
}

//2a) 
void sumManyNumbers(){
	int n = 0;
	cout << "Hvor mange tall vil du summere? ";
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++){
		int x = 0;
		cout << "Skriv inn et tall: ";
		cin >> x;
		sum += x;
	}
	cout << "Summen av tallene dine er " << sum << '\n';
}

//b)
void sumUntillZero(){
	int sum = 0;
	int x = 1;
	while(x != 0){
		cout << "Skriv inn et tall: ";
		cin >> x;
		sum += x;
	}
	cout << "Summen av tallene dine er " << to_string(sum) << '\n';
}

//c)
//Når en prosess skal gjennomføres et kjent antall ganger er for-løkke å foretrekke
//Dersom antall iterasjoner er ukjent vil man bruke while-løkke

//d)
double inputDouble(){
	double x = 0;
	cout << "Skriv inn et desimaltall: ";
	cin >> x;
	return x;
}

//e)
void NOKtoEUR(){
	double r = 1/9.75;
	double x = -1;
	while(x<0){
		cout << "Belop i NOK:\n";
		x = inputDouble()*r;
	}
	cout << "Belop i EUR: " << fixed << setprecision(2) << x << '\n';
}

//f)
//double er åpenbart å foretrekke ettersom penger kan være desimaltall

//3a)
int menuPrompt(){
	int inp = 0;
	cout << "-----\n" << "Velg funksjon:\n00) Avslutt\n01) Skriv inn og returner heltall\n02) Skriv inn og returner heltall 2: Electric Boogaloo\n03) Summer to tall\n04) Print oddetall mellom 0 og 15\n05) Konverter sekunder til ord\n06) Summer bestemt antall tall\n07) Summer til du trykker 0\n08) Skriv inn og returner desimaltall\n09) Konverter NOK til EUR\n10) Skriv ut gangetabell\n11) Kvadratformel\n12) Pythagoras\n13) Rentekalkulator\n";

	while(true){
		cin >> inp;
		if(inp >= 0){
			if(inp <= 13){
				return inp;
			}
		}
	}
}

//b)
void gangetabell(){
	int rader, kolonner;
	cout << "Antall rader: ";
	cin >> rader;
	cout << "Antall kolonner: ";
	cin >> kolonner;
	double ww = log10(rader*kolonner);
	int w = round(ww)+2;
	for(int i = 1; i <= rader; i++){
		for(int j = 1; j <= kolonner; j++){
			cout << setw(w) << to_string(i*j);
		}
		cout << '\n';
	}
}

//4a)
double discriminant(double a, double b, double c){
	return pow(b,2)-4*a*c;
}

//b)
void printRealRoots(double a, double b, double c){
	double dis = discriminant(a,b,c);
	if(dis < 0){
		cout << "Ingen reelle rotter\n";
	}
	else if(dis == 0){
		double x = -b/(2*a);
		cout << "Én reell rot: " << x << '\n';
	}
	else if(a == 0){
		double x = -c/b;
		cout << "Én reell rot: " << x << '\n';
	}
	else{
		double x1 = (-b+sqrt(dis))/(2*a);
		double x2 = (-b-sqrt(dis))/(2*a);
		cout << "To reelle rotter: " << x1 << " og " << x2 << '\n';
	}
}

//c)
void solveQuadraticEquation(){
	double a,b,c;
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "c: ";
	cin >> c;
	printRealRoots(a,b,c);
}

//5)
void pythagoras(){
	using namespace Graph_lib;
	Simple_window win{Point{100,100},300,300,"Pythagoras"};

	Polygon rightTriangle;
	rightTriangle.add(Point{150,100});
	rightTriangle.add(Point{150,140});
	rightTriangle.add(Point{180,100});
	rightTriangle.set_fill_color(Color::black);

	Polygon aSquared;
	aSquared.add(Point{150,100});
	aSquared.add(Point{150,140});
	aSquared.add(Point{110,140});
	aSquared.add(Point{110,100});
	aSquared.set_fill_color(Color::green);

	Polygon bSquared;
	bSquared.add(Point{150,100});
	bSquared.add(Point{180,100});
	bSquared.add(Point{180,70});
	bSquared.add(Point{150,70});
	bSquared.set_fill_color(Color::blue);

	Polygon cSquared;
	cSquared.add(Point{150,140});
	cSquared.add(Point{180,100});
	cSquared.add(Point{220,130});
	cSquared.add(Point{190,170});
	cSquared.set_fill_color(Color::red);

	win.attach(rightTriangle);
	win.attach(aSquared);
	win.attach(bSquared);
	win.attach(cSquared);

	win.wait_for_button();
}

//6a)
vector<int> calculateBalance(int startSaldo, int r, int yrs){
	vector<int> saldoVector(yrs);
	for(int i = 0; i < yrs; i++){
		saldoVector[i] = startSaldo*pow(1+static_cast<double>(r)/100,i);
	}
	return saldoVector;
}
//b)
void printBalance(vector<int> vec){
	int len = vec.size();
	int w1 = round(log10(len))+2;
	int w2 = round(log10(vec[len-1]))+2;
	cout << setw(w1) << "Ar: " << setw(w2) << "Saldo: \n";
	for(int i = 0; i < len; i++){
		cout << setw(w1) << i << setw(w2) << vec[i] << '\n';
	}
}

int main()
{
	while(true){
		int inp = menuPrompt();
		
		if(inp == 0){
			return 0;
		}
		else if(inp == 1){
			cout << "Oppgave 1a\n";
			inputAndPrintInteger();
		}

		else if(inp == 2){
			cout << "Oppgave 1b\n";
			int x = inputInteger();
			cout << "Ditt andre heltall er: " << x << '\n';
		}

		else if(inp == 3){
			cout << "Oppgave 1c\n";
			inputIntegersAndPrintSum();
		}

		else if(inp == 4){
			cout << "Oppgave 1e\n";
			for(int i = 0; i <= 15; i++){
				if(isOdd(i)){
					cout << i << " er et oddetall\n";
				}
				else{
					cout << i << " er et partall\n";
				}
			}
		}

		else if(inp == 5){
			cout << "Oppgave 1f\n";
			cout << printHumanReadableTime(12687318);
		}

		else if(inp == 6){
			cout << "Oppgave 2a\n";
			sumManyNumbers();
		}

		else if(inp == 7){
			cout << "Oppgave 2b\n";
			sumUntillZero();
		}

		else if(inp == 8){
			cout << "Oppgave 2d\n";
			double y = inputDouble();
			cout << "Ditt desimaltall er: " << y << '\n';
		}

		else if(inp == 9){
			cout << "Oppgave 2e\n";
			NOKtoEUR();
		}
		else if(inp == 10){
			cout << "Oppgave 3b\n";
			gangetabell();
		}
		else if(inp == 11){
			cout << "Oppgave 4\n";
			solveQuadraticEquation();
		}
		else if(inp == 12){
			cout << "Oppgave 5\n";
			pythagoras();
		}
		else if(inp == 13){
			cout << "Oppgave 6\n";
			int s, r, y;
			cout << "Start-saldo: ";
			cin >> s;
			cout << "Rente: ";
			cin >> r;
			cout << "Ar: ";
			cin >> y;

			vector<int> res = calculateBalance(s,r,y);
			printBalance(res);
		}
	}
}

//------------------------------------------------------------------------------
