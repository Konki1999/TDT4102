#include "house.h"


House::House(Point topLeft, Point topRoof)
: base{topLeft, 2*(topRoof.x-topLeft.x), topLeft.y-topRoof.y}
{
	roof.add(topRoof);
	roof.add(topLeft);
	roof.add(Point{topLeft.x + base.width(), topLeft.y});

	Color col = Color::red;
	base.set_color(Color::black);
	base.set_fill_color(col);
	roof.set_color(Color::black);
	roof.set_fill_color(col);
}

void House::attach_to(Graph_lib::Window& win) {
	win.attach(base);
	win.attach(roof);
}

/*
----------------------------------------------------------------------------------
*/

EmptyHouse::EmptyHouse(Point topLeft, Point topRoof)
: House(topLeft, topRoof)
{}

void EmptyHouse::attach_to(Graph_lib::Window& win) {
	House::attach_to(win);
}

HouseWithWindow::HouseWithWindow(Point topLeft, Point topRoof)
: House(topLeft, topRoof),
  w{shift(topLeft, width()/4, height()/3), height()/3}
{}

void HouseWithWindow::attach_to(Graph_lib::Window& win) {
	House::attach_to(win);
	w.attach_to(win);
}

HouseFacade::HouseFacade(Point topLeft, Point topRoof)
: HouseWithWindow(topLeft, topRoof),
  d{shift(topLeft, width()/2, height()), 2*height()/3, width()/4}
{}

void HouseFacade::attach_to(Graph_lib::Window& win) {
	HouseWithWindow::attach_to(win);
	d.attach_to(win);
}