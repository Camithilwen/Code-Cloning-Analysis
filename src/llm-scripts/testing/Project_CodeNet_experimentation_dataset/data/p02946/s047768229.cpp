/* 
 * Project: AtCoder Beginners Contest 137 B - One Clue
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/09/01
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
using namespace std;

int32_t k;
int32_t coord_x;

void solve() {

    for (int i=-k+1;i<k;i++) {
        printf("%d ", coord_x+i);
    }

    printf("\n");

}

int main() {

    scanf("%d", &k);
    scanf("%d", &coord_x);

    solve();

}
