#include "Meeting.h"
#include <ostream>
#include <cmath>

map<Campus,string> campusName {{Campus::Trondheim,"Trondheim"},{Campus::Aalesund,"Ålesund"},{Campus::Gjoevik,"Gjøvik"}};

ostream& operator<<(ostream& os, Campus& c){
    os << campusName.at(c);
    return os;
}

void testMeeting(){
    Campus c0 = Campus::Gjoevik;
    cout << "Test campus: " << c0 << endl;

    Car car0 = Car(4);
    Car car1 = Car(0);
    Car car2 = Car(2);

	const Person per0 = Person("Konrad", "kejervel@stud.ntnu.no", &car0);
	const Person per1 = Person("Elias", "eliasos@stud.ntnu.no", &car1);
    const Person per2 = Person("Astrid", "astriblu@stud.ntnu.no");
    const Person per3 = Person("Anders", "andertid@stud.ntnu.no", &car2);
    const Person per4 = Person("Irma","irmahf@stud.ntnu.no");

    Meeting met0 = Meeting(2,15,17,Campus::Trondheim,"For lange øvinger",&per0);
    met0.addParticipant(&per1);
    met0.addParticipant(&per2);
    cout << met0 << endl;

    Meeting met1 = Meeting(2, 14, 16,Campus::Trondheim,"Lange øvinger er gøy",&per3);
    met1.addParticipant(&per4);
    cout << met1 << endl;

    vector<const Person*> drivers = met0.findPotentialCoDriving();
    cout << "Potential drivers: \n";
    for(auto& x : drivers){
        cout << " - " << x->getName() << endl;
    }
}

Meeting::Meeting(int d, int sT, int eT, Campus lo, string s, const Person* le) : day{d}, startTime{sT}, endTime{eT}, location{lo}, subject{s}, leader{le} {
    addParticipant(leader);
    meetings.insert(this);
};

Meeting::~Meeting(){
    meetings.erase(this);
};

int Meeting::getDay() const{
    return day;
}

int Meeting::getStartTime() const{
    return startTime;
}

int Meeting::getEndTime() const{
    return endTime;
}

Campus Meeting::getLocation() const{
    return location;
}

string Meeting::getSubject() const{
    return subject;
}

const Person* Meeting::getLeader() const{
    return leader;
}

set<const Person*> Meeting::getParticipants() const{
    return participants;
}

void Meeting::addParticipant(const Person* p){
    participants.insert(p);
}

vector<string> Meeting::getParticipantList() const{
    vector<string> participantList(participants.size());
    int iterator = 0;
    for(auto i : participants){
        participantList[iterator] = i->getName();
        iterator++; 
    }
    return participantList;
}

vector<const Person*> Meeting::findPotentialCoDriving() const{
    vector<const Person*> drivers;
    for(const Meeting* x : meetings){
        if((x->getLocation() == this->getLocation()) && (x->getDay() == this->getDay()) && (abs(x->getStartTime() - this->getStartTime()) <= 1) && (abs(x->getEndTime() - this->getEndTime()) <= 1)){
            for(const Person* y : x->getParticipants()){
                if(y->hasAvailableSeats()){
                    drivers.push_back(y);
                }
            }
        }
    }
    return drivers;
}

ostream& operator<<(ostream&os, Meeting& m){
    Campus location = m.getLocation();
    os << "Day: " << m.getDay() 
       << "\nStart time: " << m.getStartTime()
       << "\nEnd time: " << m.getEndTime()
       << "\nLocation: " << location
       << "\nSubject: " << m.getSubject()
       << "\nLeader: " << m.getLeader()->getName()
       << "\nParticipants:" << endl;
    vector<string> lst = m.getParticipantList();
    for(auto x : lst){
        os << " - " << x << endl;
    }
    return os;
}