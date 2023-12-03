#include "util.h"

int main() {

    // Open up file stream
    std::ifstream f_id;
    f_id.open("input.txt", std::ios_base::in);
    
    string line, prev;
    int count = 0;
    int id = 0;


    // Iterate through and parse each line
    while(getline(f_id, line)){
        vector<string> line_vec = getSubWords(line);

        id = stoi(line_vec[1]);
        for (int i = 1; i < line_vec.size(); i++) {
            id = parseLine(line_vec[i], line_vec[i-1], id);
            if (id == 0)
                break;
        }
        count += id;
    }
    cout << count << endl;
    return 0;
}