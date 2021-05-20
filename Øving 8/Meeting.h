#pragma once
#include "Person.h"


enum class Campus {Trondheim, Aalesund, Gjoevik};

ostream& operator<<(ostream& os, Campus& c);

void testMeeting();

class Meeting{
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    set<const Person*> participants;
    static inline set<const Meeting*> meetings{};
public:
    Meeting(int d, int sT, int eT, Campus lo, string s, const Person* le);
    ~Meeting();
    int getDay() const;
    int getStartTime() const;
    int getEndTime() const;
    Campus getLocation() const;
    string getSubject() const;
    const Person* getLeader() const;
    set<const Person*> getParticipants() const;
    void addParticipant(const Person* p);
    vector<string> getParticipantList() const;
    vector<const Person*> findPotentialCoDriving() const;
};

ostream& operator<<(ostream&os, Meeting& m);