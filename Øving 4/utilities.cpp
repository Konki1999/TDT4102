#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes){
    for(int i = 0; i < numTimes; i++){
        startValue+= increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes){
    for(int i = 0; i < numTimes; i++){
        startValue+= increment;
    }
}

void swap(double& a, double& b){
    double temp = a;
    a = b;
    b = temp;
}

void printStudent(Student student){
    cout << "Name: " << student.name << endl
         << "Study program: " << student.studyProgram << endl
         << "Age: " << student.age << endl << endl;
}

bool isInProgram(Student student, string program){
    bool inProgram = false;
    toLower(student.studyProgram);
    toLower(program);
    if(student.studyProgram == program){
        inProgram = true;
    }
    return inProgram;
}

void charToLower(char& a){
    if(a >= 'A' && a <= 'Z'){
        a += 32;
    }
}

void toLower(string& str){
    for(char& x : str){
        charToLower(x);
    }
}

void charToUpper(char& a){
    if(a >= 'a' && a <= 'z'){
        a -= 32;
    }
}

void toUpper(string& str){
    for(char& x : str){
        charToUpper(x);
    }
}

string randomizeString(int lenOfStr, char start, char end){
    charToUpper(start);
    charToUpper(end);
    string str = "";
    for(int i = 0; i < lenOfStr; i++){
        char c = start + rand()%(end-start+1);
        str += c;
    }
    return str;
}

string readInputToString(int n){
    int i = 0;
    string str = "";
    while(i < n){
        char c;
        cout << "Please enter a letter: ";
        cin >> c;
        if(std::isalpha(c)){
            str += c;
            i++;
        }
        else{
            cout << "Please enter a valid letter!\n";
            continue;
        }
    }
    return str;
}

int countChar(string str, char c){
    int counter = 0;
    for(char x : str){
        if(x == c){
            counter++;
        }
    }
    return counter;
}

double minOfTwo(double a, double b){
    if(a < b){
        return a;
    }
    else{
        return b;
    }
}