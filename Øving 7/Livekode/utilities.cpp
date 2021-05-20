#include "utilities.h"

WallWindow::WallWindow(Point centre, int height)
: win{Point{centre.x-height/2, centre.y-height/2}, height, height},
  hSpoke{Point{centre.x-height/2, centre.y}, Point{centre.x+height/2, centre.y}},
  vSpoke{Point{centre.x, centre.y-height/2}, Point{centre.x, centre.y+height/2}}
{
	win.set_color(Color::black);
	win.set_fill_color(Color::white);
	hSpoke.set_color(Color::black);
	vSpoke.set_color(Color::black);
}

void WallWindow::attach_to(Graph_lib::Window& w) {
	w.attach(win);
	w.attach(hSpoke);
	w.attach(vSpoke);
}

Door::Door(Point lowerLeft, int height, int width)
: frame{Point{lowerLeft.x, lowerLeft.y-height}, width, height},
  knob{Point{lowerLeft.x+width/6, lowerLeft.y-height/2}, width/10}
{
	frame.set_color(Color::black);
	frame.set_fill_color(Color::light_gray);
	knob.set_color(Color::black);
	knob.set_fill_color(Color::black);
}

void Door::attach_to(Graph_lib::Window& w) {
	w.attach(frame);
	w.attach(knob);
}

Point shift(Point p, int xShift, int yShift) {
	// Shifts point xShift to the right and yShift downwards
	return Point{p.x+xShift, p.y+yShift};
}