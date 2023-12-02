#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/// @brief Checks line for digits in form of string
/// @param line (string) Current string of line being read
/// @param len (int) Length of line
/// @param idx (int) Current starting index we're checking in line
/// @return (string) Output corresponding to string of digit
string check_str(string line, int len, int idx) {
    // arr of strings - lazy method
    string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string characters[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    // Iterate through line from prescribed start and compare to each string in nums arr
    // Loops break if mismatch occurs and moves on to next string in nums
    // If inner loop reaches end, return corresponding string
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < nums[i].length(); j++) {
            if(line[idx + j] != nums[i][j]) {
                break;
            }
            else if (j == nums[i].length()-1) {
                return characters[i];
            }
        }
    }

    return "";
}

/// @brief Parses each line in file for first and last int
/// @param line (string) line to be parsed
/// @return (int) integer of combined first and last nums
int parseLine(string line) {
    string first, last;

    int len = line.length();

    // Find first num in string
    for (int i = 0; i < len; i++) {

        // Check for explicit digit
        if (isdigit(line[i])) {
            first = line[i];
            break;
        }

        // Check for implicit digit
        string result = check_str(line, len, i);
        if (result != ""){
            first = result;
            break;
        }
    }

    // Find last num in string
    for (int i = len-1; i >= 0; i--) {

        // Check for explicit digit
        if (isdigit(line[i])) {
            last = line[i];
            break;
        }
        
        // Check for implicit digit
        string result = check_str(line, len, i);
        if (result != ""){
            last = result;
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
