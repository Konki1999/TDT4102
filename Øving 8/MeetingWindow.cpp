#include "MeetingWindow.h"

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title) : quitBtn{{w-btnW-pad,pad},btnW,btnH,"Quit",cb_quit}, personName{{fieldPad,pad},fieldW,fieldH,"Name"}, personEmail{{fieldPad,2*pad+fieldH},fieldW,fieldH,"Email"}, personNewBtn{{fieldPad,3*pad+2*fieldH},btnW,btnH,"Add person",cb_new_person}, Window(xy, w, h, title){
    attach(quitBtn);
    attach(personName);
    attach(personEmail);
    attach(personNewBtn);
}

//MeetingWindow::~MeetingWindow(){
//    delete[] people;
//}

void MeetingWindow::cb_quit(Address, Address pw){
    reference_to<MeetingWindow>(pw).hide();
}

void MeetingWindow::cb_new_person(Address, Address pw){
    reference_to<MeetingWindow>(pw).addPerson();

}

void MeetingWindow::addPerson(){
    string name = personName.get_string();
    if(alphastr(name) && name != ""){
        people.push_back(new Person(name, personEmail.get_string()));
    }
    personName.clear_value();
    personEmail.clear_value();
}

vector<Person*> MeetingWindow::getPeople() const{
    return people;
}

void testGUI(){
    MeetingWindow win = MeetingWindow(Point {150,150}, 400, 200, "Vindu");
    gui_main();
    vector<Person*> vec = win.getPeople();
    cout << "\nPeople who were added through GUI:\n";
    for(Person* x : vec){
        cout << *x << endl;
    }
}