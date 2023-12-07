#include "util.h"


int main() {
    // Open up file stream
    std::ifstream f_id;
    f_id.open("input.txt", std::ios_base::in);
    vector<string> arr[ROWS][3]; 
    string line;
    int col = 0;
    int row = 0;
    int p1_result = 0;

    // Iterate through and parse each line
    while(getline(f_id, line)){
        col = 0;
        string curr = "";

        for (char& c: line) {
            if (isspace(c) && curr != ""){
                arr[row][col].push_back(curr);
                curr = "";
            }
            else if (c == ':' || c == '|') {
                if (curr != ""){
                    arr[row][col].push_back(curr);
                    curr = "";
                }
                col++;
            }
            else if (!isspace(c)){
                curr += c;
            }
        }
        arr[row][col].push_back(curr);
        row++;
    }

    for (int i = 0; i < ROWS; i++) {
        p1_result += pow(2, (find_nums(arr[i][1], arr[i][2]))-1);
    }

    cout << p1_result << endl;
    

    return 0;
}