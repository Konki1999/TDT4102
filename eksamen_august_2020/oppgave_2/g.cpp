#include "g.h"

void insertLineNumbers(string filename){
    ofstream outputFile(filename);
    if (!outputFile){
        cout << "Can not open file\n";
    }
    else{
        map<int,string> intToString{
            {1,"First"},
            {2,"Second"},
            {3,"Third"},
            {4,"Fourth"},
            {5,"Fifth"},
            {6,"Sixth"},
            {7,"Seventh"},
            {8,"Eighth"},
            {9,"Ninth"},
            {10,"Tenth"}
        };
        for(int i = 1; i <= 10; i++){
            outputFile << intToString.at(i) << "line \n";
        }
        outputFile.close();
    }   
}