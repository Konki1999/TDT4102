#include "NTNULogo.h"

#include "Simple_window.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

constexpr Point origo{Point{0, 0}};
constexpr int radius{85};
constexpr int pad{100};
const string title{"NTNU Logo"};

void drawNTNULogo(){

    //Kalle konstrutører som trengs for å tegne logo:
    Simple_window win{origo, 5* pad, 5* pad, title}; 
    

    //Sette fyll-farge:

    //Fjerne kanter: Shape.set_color(Color::invisible): 

    //Tegne figurer:

    win.wait_for_button();
}
