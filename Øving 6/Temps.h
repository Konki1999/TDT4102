#pragma once
#include "textProcessing.h"

struct Temps{
    double max;
    double min;
};

istream& operator>>(istream& is, Temps& t);
vector<Temps> readTemps(string filename);
void tempStats(vector<Temps> temps);
void testTemps();