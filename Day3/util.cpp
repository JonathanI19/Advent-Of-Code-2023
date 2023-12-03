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
