#include "util.h"

int main() {

    // Open up file stream
    std::ifstream f_id;
    f_id.open("input.txt", std::ios_base::in);
    
    string line, prev;
    int sum = 0;
    int id = 0;


    // Iterate through and parse each line
    while(getline(f_id, line)){
        vector<string> line_vec = getSubWords(line);

        id = stoi(line_vec[1]);
        int max_red = 0, max_blue = 0, max_green = 0;
        for (int i = 1; i < line_vec.size(); i++) {
            parsePower(line_vec[i], line_vec[i-1], max_red, max_green, max_blue);
        }
        sum += (max_red * max_blue * max_green);
    }
    cout << sum << endl;
    return 0;
}