#include "util.h"

vector <string> getSubWords(string s) {
    vector<string> result;
    string curr = "";
    for (char& c: s) {
        if (isspace(c) || c == ';' || c == ',' || c == ':'){
            result.push_back(curr);
            curr = "";
        }
        else {
            curr += c;
        }
    }
    result.push_back(curr);

    return result;
}

int parseLine(string check, string val, int id) {
    int max_red = 12;
    int max_green = 13;
    int max_blue = 14;

    if (check == "red"){
        if (stoi(val) > max_red)
            id = 0;
    }
    else if (check == "blue") {
        if (stoi(val) > max_blue)
            id = 0;
    }
    else if (check == "green") {
        if (stoi(val) > max_green)
            id = 0;
    }

    return id;
}