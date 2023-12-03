#ifndef UTIL_H
#define UTIL_H

#define ROWS 140
#define COLS 140

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

bool checkDigit(char);
bool checkSymbol(char[ROWS][COLS], int, int);

#endif