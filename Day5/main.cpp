#include "util.h"


int main() {
    std::ifstream f_id;
    f_id.open("input.txt", std::ios_base::in);
    string line;

    while(getline(f_id, line)){
        for (char& c: line) {
        }
    }
    return 0;
}
