#include "textProcessing.h"

void createFile(string filename){
    ofstream file{filename};
}

void writeToFile(string filename){
    fstream writeFile;
    writeFile.open(filename, ios::out);
    if(!writeFile){
        createFile(filename);
    }
    bool write = true;
    while(write){
        string str;
        cout << "Enter a word: ";
        cin >> str;
        if(str == "quit"){
            write = false;
            writeFile.close();
            break;
        }
        writeFile << str << endl;
    }
}

void readFromFile(string filename){
    fstream readFile;
    readFile.open(filename, ios::in);
    if (!readFile) {
        cout << "No such file \"" << filename << "\"\n";
    }
    else{
        string line;
        int i = 0;
        createFile("indexedLines.txt");
        fstream indexedLines;
        indexedLines.open("indexedLines.txt", ios::out);
        while (getline(readFile, line)) {
            string str = to_string(i) + " " + line;
            indexedLines << str << endl;
            i++;
        }
        indexedLines.close();
    }
    readFile.close();
}

vector<int> charCountInFile(string filename, char endChar){
    vector<int> charCount(endChar - 'a' + 1);
    fstream readFile;
    readFile.open(filename, ios::in);
    if (!readFile) {
        cout << "No such file \"" << filename << "\"\n";
    }
    else{
        string line;
        while (getline(readFile, line)) {
            for(int i = 0; i < line.length(); i++){
                char x = tolower(line[i]);
                if('a' <= x && x <= endChar){
                    charCount[x - 'a'] ++;
                }
            }
        }
    }
    return charCount;
}