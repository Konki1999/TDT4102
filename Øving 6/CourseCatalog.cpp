#include "CourseCatalog.h"

CourseCatalog::CourseCatalog(){

};

void CourseCatalog::addCourse(string code,string name){
    codeToName[code] = name;
}

void CourseCatalog::removeCourse(string code){
    codeToName.erase(code);
}

string CourseCatalog::getCourse(string code){
    string name = codeToName.at(code);
    return name;
}

void CourseCatalog::writeToFile(string filename){
    fstream writeFile;
    writeFile.open(filename, ios::out);
    if(!writeFile){
        createFile(filename);
    }
    for(auto elem : codeToName){
        writeFile << elem.first << ", " << elem.second << endl;
    }
}

void CourseCatalog::readFromFile(string filename){
    fstream readFile;
    readFile.open(filename, ios::in);
    if (!readFile) {
        cout << "No such file \"" << filename << "\"\n";
    }
    else{
        string line;
        while(getline(readFile,line)){
            stringstream stream(line);
            string word;
            vector<string> wordLst;
            while(getline(stream,word,',')){
                wordLst.push_back(word);
            }
            addCourse(wordLst[0],wordLst[1]);
        }
    }
}

ostream& operator<<(ostream& os,const CourseCatalog& c){
    for(auto elem : c.codeToName){
        os << elem.first << ", " << elem.second << endl;
    }
    return os;
}

void testCourses(){
    CourseCatalog catalog{};
    catalog.addCourse("TDT4110","Informasjonsteknologi grunnkurs");
    catalog.addCourse("TDT4102","Prosedyre- og objektorientert programmering");
    catalog.addCourse("TMA4100","Matematikk 1");
    cout << catalog;
    cout << endl;
    catalog.addCourse("TDT4102","C++");
    cout << catalog;
    cout << endl;
    catalog.writeToFile("test.txt");
    CourseCatalog catalog1{};
    catalog1.readFromFile("test.txt");
    cout << catalog1 << endl;
}