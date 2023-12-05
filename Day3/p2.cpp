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

    parseGear my_parser(arr);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            my_parser.updateCurr(i, j);
            my_parser.parse();
            count += my_parser.getResult();
        }
    }

    cout << count << endl;
    return 0;
}
