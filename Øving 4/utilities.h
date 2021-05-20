#pragma once
#include "std_lib_facilities.h"
#include <cstdlib>

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swap(double& a, double& b);

struct Student{
    string name;
    string studyProgram;
    int age;
};

void printStudent(Student student);
bool isInProgram(Student student, string program);

void charToLower(char& a);
void toLower(string& str);

void charToUpper(char& a);
void toUpper(string& str);

string randomizeString(int lenOfStr, char start, char end);
string readInputToString(int n);
int countChar(string str, char c);

double minOfTwo(double a, double b);