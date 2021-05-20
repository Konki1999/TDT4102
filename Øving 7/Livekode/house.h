#pragma once

#include "Graph.h"
#include "GUI.h"
#include "utilities.h"

using namespace Graph_lib;

class Building
{
public:
	Building(const Building&) = delete;
	Building& operator=(const Building&) = delete;


	Building() {}

	virtual void attach_to(Graph_lib::Window&) = 0;

	virtual ~Building() {}
};

class House : public Building
{
public:
	House(Point topLeft, Point topRoof);
	void attach_to(Graph_lib::Window& win) override = 0;
	int width() {return base.width();}
	int height() {return base.height();}
private:
	Polygon roof;
	Rectangle base;
};

class EmptyHouse : public House
{
public:
	EmptyHouse(Point topLeft, Point topRoof);
	void attach_to(Graph_lib::Window& win) override;
};

class HouseWithWindow : public House
{
private:
	WallWindow w;
public:
	HouseWithWindow(Point topLeft, Point topRoof);
	void attach_to(Graph_lib::Window& win) override;
};

class HouseFacade : public HouseWithWindow
{
private:
	Door d;
public:
	HouseFacade(Point topLeft, Point topRoof);
	void attach_to(Graph_lib::Window& win) override;
};