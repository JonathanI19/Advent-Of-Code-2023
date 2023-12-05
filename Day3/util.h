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


class parseGear {
    private:
        int curr_row, curr_col, num_count, gear_prod, gear_1, gear_2;
        char arr[ROWS][COLS];
        void determineNum(int, int);

    public:
        parseGear(char[ROWS][COLS]);
        void updateCurr(int, int);
        void parse();

        int getResult();



};

#endif