#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/// @brief Parses each line in file for first and last int
/// @param line (string) line to be parsed
/// @return (int) integer of combined first and last nums
int parseLine(string line) {
    string first, last;
    int len = line.length();

    // Find first num in string
    for (int i = 0; i < len; i++) {
        if (isdigit(line[i])){
            first = line[i];
            break;
        }
    }

    // Find last num in string
    for (int i = len-1; i >= 0; i--) {
        if (isdigit(line[i])) {
            last = line[i];
            break;
        }
    }

    // Combine nums and output converted int
    string num = first + last;
    return stoi(num);
}

int main() {

    // Open up file stream
    std::ifstream f_id;
    f_id.open("input1.txt", std::ios_base::in);
    
    string line;
    int sum = 0;

    // Iterate through and parse each line
    while(getline(f_id, line)){
        sum += parseLine(line);
    }

    // Output
    cout << sum << endl;
  return 0;
}
