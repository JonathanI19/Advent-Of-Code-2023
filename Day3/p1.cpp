#include "util.h"

int main() {

    // Open up file stream
    std::ifstream f_id;
    f_id.open("input.txt", std::ios_base::in);
    
    string line;
    int count = 0;
    int id = 0;
    char arr[ROWS][COLS];

    int i = 0, j = 0;

    // Iterate through and parse each line
    while(getline(f_id, line)){
        for (char& c:line) {
            arr[i][j] = c;
            j++;
        }
        j = 0;
        i++;
    }

    for (int i = 0; i < ROWS; i++) {
        string curr = "";
        bool isPart = false;
        for (int j = 0; j < COLS; j++) {
            if(checkDigit(arr[i][j]) == true) {
                curr += arr[i][j];
                if (isPart == false) {
                    isPart = checkSymbol(arr, i, j);
                }
            }
            else {
                if (curr != "" && isPart == true) {
                    count += stoi(curr);
                }
                curr = "";
                isPart = false;
            }
        }
        if (curr != "" && isPart == true) {
            count += stoi(curr);
        }
    }

    cout << count << endl;
    return 0;
}
