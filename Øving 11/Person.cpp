#include "Person.h"

Person::Person(string fName, string sName) : fName{fName}, sName{sName}{};

void Person::setFName(string name){
    fName = name;
}
void Person::setSName(string name){
    sName = name;
}
string Person::getFName() const{
    return fName;
}
string Person::getSName() const{
    return sName;
}

ostream& operator<<(ostream &os, Person &p){
    os << p.fName << ' ' << p.sName;
    return os;
}

void insertOrdered(list<Person> &l, const Person& p){
    string fullNameP = p.getFName() + p.getSName();
    if(l.empty() || fullNameP >= l.rbegin()->getFName() + l.rbegin()->getSName()){
        l.push_back(p);
    }
    else{
        for(list<Person>::iterator it = l.begin(); it != l.end(); it++){
            string fullNameIt = it->getFName() + it->getFName();
            if(fullNameP < fullNameIt){
                l.insert(it,p);
                break;
            }
        }
    }
}