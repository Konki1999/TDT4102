#include "tests.h"
#include "utilities.h"

void testCallByValue(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
         << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << result << endl;
}

void testCallByReference(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10;

    cout << "v0: " << v0;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << " increment: " << increment
         << " iterations: " << iterations
         << " result: " << v0 << endl;
}

void testSwap(){
    //Pass by value
    double a = 12.0;
    double b = 20.5;
    cout << "Before swap:\n"
         << "a = " << a << " b = " << b << endl;
    swap(a,b);
    cout << "After swap:\n"
         << "a = " << a << " b = " << b << endl;
}

void testToLower(){
    string str = "ABCD";
    cout << "String before toLower(): " << str << endl;
    toLower(str);
    cout << "String after toLower(): " << str << endl;
}

void testStudent(){
    Student newStudent{"Konrad", "BFY", 21};
    cout << "Student before bool test with case conversion: \n";
    printStudent(newStudent);
    cout << "Check if student is in BFY: \n";
    if(isInProgram(newStudent,"BFY")){
        cout << "Yes!\n\n";
    }
    else{
        cout << "No!\n\n";
    }
    cout << "Check if student is in bfy: \n";
    if(isInProgram(newStudent,"bfy")){
        cout << "Yes!\n\n";
    }
    else{
        cout << "No!\n\n";
    }
    cout << "Check if student is in BMAT: \n";
    if(isInProgram(newStudent,"BMAT")){
        cout << "Yes!\n\n";
    }
    else{
        cout << "No!\n\n";
    }
    cout << "Check if student is in bmat: \n";
    if(isInProgram(newStudent,"bmat")){
        cout << "Yes!\n\n";
    }
    else{
        cout << "No!\n\n";
    }
    cout << "Student after bool test with case conversion: \n";
    printStudent(newStudent);

}

void testString(){
    int len = 8;
    char start = 'A';
    char end = 'F';
    string grades = randomizeString(len, start, end);
    cout << "Random string of grades: " << grades << endl;
    int num = end-start+1;
    vector<int> gradeCount(num);
    string str = "";
    for(char c = end; c >= start; c-=1){
        str += c;
    }
    for(char x : str){
        int index = (x+1)%(num);
        gradeCount[index] = countChar(grades,x);
    }
    double sum = 0;
    for(int i = 0; i < num; i++){
        sum += i*gradeCount[i];
    }
    double avg = sum/len;
    cout << "The average grade is: " << avg << endl;
}

void testReadToString(){
    int len = 4;
    string str = readInputToString(len);
    cout << "You entered: " << str << endl;
}

void testCountChar(){
    string str = "AaBbBcD";
    char c = 'B';
    int numB = countChar(str,c);
    cout << "The letter \'" << c << "\' occurs " << numB << " times in the string \"" << str << "\"\n";
}