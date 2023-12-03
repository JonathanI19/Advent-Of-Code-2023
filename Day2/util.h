#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> getSubWords(string);
int parseLine(string, string, int);
void parsePower(string, string, int&, int&, int&);
#endif