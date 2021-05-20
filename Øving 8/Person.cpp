#include "Person.h"

Person::Person(string n, string e, Car* c) : name{n}, email{e}, car{c} {};

string Person::getName() const{
    return name;
}

string Person::getEmail() const{
    return email;
}

void Person::setEmail(string email_address){
    email = email_address;
}

bool Person::hasAvailableSeats() const{
    if(car){
        return car->hasFreeSeats();
    }
    else{
        return false;
    }
    
}

ostream& operator<<(ostream& os, const Person& p){
    os << "Name: " << p.name << "\nEmail: " << p.email << endl;
    if(p.hasAvailableSeats()){
        os << "Has available seats\n";
    }
    else{
        os << "Does not have available seats\n";
    }
    return os;
}

void testPerson(){
    Car car0 = Car(4);
	Person per0 = Person("Konrad", "kejervel@stud.ntnu.no", &car0);
	cout << per0 << endl;
    Car car1 = Car(0);
	Person per1 = Person("Elias", "eliasos@stud.ntnu.no", &car1);
	cout << per1 << endl;
    Person per2 = Person("Astrid", "astriblu@stud.ntnu.no");
    cout << per2 << endl;
}