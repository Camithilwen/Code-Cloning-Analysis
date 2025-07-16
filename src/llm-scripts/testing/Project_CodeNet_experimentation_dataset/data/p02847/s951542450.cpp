/* 
 * Project: AtCoder Beginners Contest 146 A - Can't Wait for Holiday / 
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/07
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstring>
using namespace std;

char s[3];

void solve() {

    const char *week[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    for (int i=0;i<7;i++) {
        if (strcmp(s, week[i]) == 0) {
            printf("%d\n", 7-i);
            return;
        }
    }

}

int main() {

    scanf("%s", s);

    solve();

}