#include "Simple_window.h"
#include "house.h"

using namespace Graph_lib;

// Window and emoji size
constexpr int xmax = 1000;
constexpr int ymax =  600;
constexpr int pad  =   50;
constexpr Point startLeft {200, 300};
constexpr Point startRoof {300, 200};

//------------------------------------------------------------------------------'

int main()
{
	const Point tl{100, 100};
	const string win_label{"House"};
	Simple_window win{tl, xmax, ymax, win_label};
	win.color(Color::white);
	
	//---------------------------------------------------------------------------
	Vector_ref<Building> buildings;
	EmptyHouse eHouse {startLeft, startRoof};
	HouseWithWindow wHouse {shift(startLeft, eHouse.width()+pad, 0),
						    shift(startRoof, eHouse.width()+pad, 0)};
	HouseFacade fHouse {shift(startLeft, 2*(eHouse.width()+pad), 0),
 						shift(startRoof, 2*(eHouse.width()+pad), 0)};
	
	buildings.push_back(eHouse);
	buildings.push_back(wHouse);
	buildings.push_back(fHouse);
	for (int i=0; i<buildings.size(); i++) {
		buildings[i].attach_to(win);
	}
	//---------------------------------------------------------------------------

	win.wait_for_button();

	string line;
	
}

//------------------------------------------------------------------------------
