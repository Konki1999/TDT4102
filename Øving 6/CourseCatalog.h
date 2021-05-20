#pragma once
#include "textProcessing.h"

class CourseCatalog{
private:
    map<string,string> codeToName {};
    string getCourse(string code);
public:
    CourseCatalog();
    void addCourse(string code, string name);
    void removeCourse(string code);
    void writeToFile(string filename);
    void readFromFile(string filename);
    friend ostream& operator<<(ostream& os,const CourseCatalog& c);
};

void testCourses();