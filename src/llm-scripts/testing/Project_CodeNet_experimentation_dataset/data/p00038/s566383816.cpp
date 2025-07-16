#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

int c[5];// card

bool straight()
{
    if(c[4]==13 && c[3]==12 && c[2]==11 && c[1]==10 && c[0]==1)
        return true;
    for(int i=0; i<4; i++) {
        if(c[i+1] - c[i] != 1)
            return false;
    }
    return true;
}

int main(void)
{
    while(~scanf("%d,%d,%d,%d,%d", c, c+1, c+2, c+3, c+4)) {
        sort(c, c+5);
        if(c[0] == c[3] || c[1] == c[4]) {
            puts("four card");
        } else if((c[0] == c[2] && c[3] == c[4]) ||
                (c[0] == c[1] && c[2] == c[4])) {
            puts("full house");
        } else if(straight()) {
            puts("straight");
        } else if(c[0]==c[2] || c[1]==c[3] || c[2]==c[4]) {
            puts("three card");
        } else if((c[0]==c[1] && (c[2]==c[3] || c[3]==c[4])) ||
                (c[1]==c[2] && c[3]==c[4])) {
            puts("two pair");
        } else if(c[0]==c[1] || c[1]==c[2] || c[2]==c[3] || c[3]==c[4]) {
            puts("one pair");
        } else {
            puts("null");
        }   
    }


    return 0;
}