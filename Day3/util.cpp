#include "util.h"

bool checkDigit(char c) {
    bool isDigit = false;

    if (isdigit(c)) {
        isDigit = true;
    }

    return isDigit;
}

bool checkSymbol(char arr[ROWS][COLS], int i, int j){

    for (int x = -1; x <= 1; x++){
        for (int y = -1; y <= 1; y++){
            
            if (i+x >= 0 && i+x <= 139 && j+y >=0 && j+y <= 139){
                char val = arr[i+x][j+y];
                if (val == '*' || val == '%' || val == '&' || val == '#' || val == '$'|| val == '+' || val == '=' || val == '@' || val == '-' || val == '/') {
                    return true;
                }
            
            }
        }
    }


    return false;
}

parseGear::parseGear(char input_arr[ROWS][COLS]) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++){
            arr[i][j] = input_arr[i][j];
        }
    }
    num_count = 0;
}

void parseGear::updateCurr(int row, int col) {
    curr_row = row;
    curr_col = col;
    num_count = 0;

    gear_prod = 1;
}

void parseGear::parse() {
    if (arr[curr_row][curr_col] == '*'){
        bool sameNum = false;

        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {

                if (curr_row+x >= 0 && curr_row+x <= 139 && curr_col+y >=0 && curr_col+y <= 139){
                    char val = arr[curr_row+x][curr_col+y];
                    
                    if (isdigit(val) && !sameNum) {
                        num_count++;
                        determineNum((curr_row+x), (curr_col+y));
                        sameNum = true;
                    }
                    else if (!isdigit(val)){
                        sameNum = false;
                    }
                }
            }
            sameNum = false;
        }
    }
    if (num_count != 2) {
        gear_prod = 0;
    }
}

void parseGear::determineNum(int row, int col) {
    string temp = "";

    while (col >= 0) {
        col--;
        if (!isdigit(arr[row][col])) {
            col++;
            break;
        }
    }
    while (isdigit(arr[row][col])) {
        temp+= arr[row][col];
        col++;
    }
    gear_prod *= stoi(temp);
}

int parseGear::getResult(){
    return gear_prod;
}

