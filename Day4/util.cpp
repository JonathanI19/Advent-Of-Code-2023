#include "util.h"

int find_nums(vector<string> winning, vector<string> tix) {
    int count = 0;

    for (string win_num: winning) {
        if(find(tix.begin(), tix.end(), win_num) != tix.end()){
            count++;
        }
    }

    if(count > 0) {
        // return pow(2, count-1);
        return count;
    }
    else {
        return 0;
    }
}