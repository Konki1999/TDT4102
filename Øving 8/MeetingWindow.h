#pragma once
#include "Meeting.h"
#include "Graph.h"
#include "Window.h"
#include "GUI.h"
#include "utilities.h"

using namespace Graph_lib;

class MeetingWindow : public Graph_lib::Window{
private:
    Button quitBtn;
    In_box personName;
    In_box personEmail;
    Button personNewBtn;
    vector<Person*> people;
public:
    MeetingWindow(Point xy, int w, int h, const string& title);
    //~MeetingWindow();
    static constexpr int btnW = 75; 
	static constexpr int btnH = 20;
	static constexpr int pad = 20;
	static constexpr int fieldPad = 60;
	static constexpr int fieldW = 100;
	static constexpr int fieldH = 15;
    static void cb_quit(Address, Address pw);
    static void cb_new_person(Address, Address pw);
    void addPerson();
    vector<Person*> getPeople() const;
};

void testGUI();