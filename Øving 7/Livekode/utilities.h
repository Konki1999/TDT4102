#pragma once

#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

class WallWindow
{
private:
	Rectangle win;
	Line hSpoke;
	Line vSpoke;
public:
	WallWindow(Point centre, int height);
	void attach_to(Graph_lib::Window& w);
};

class Door
{
private:
	Rectangle frame;
	Circle knob;
public:
	Door(Point lowerLeft, int height, int width);
	void attach_to(Graph_lib::Window& w);
};

// Shifts point xShift to the right and yShift downwards
Point shift(Point p, int xShift, int yShift);