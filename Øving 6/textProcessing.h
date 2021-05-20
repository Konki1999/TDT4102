#pragma once

#include <iostream>
#include <fstream>
#include "std_lib_facilities.h"

void createFile(string filename);
void writeToFile(string filename);
void readFromFile(string filename);
vector<int> charCountInFile(string filename, char endChar);