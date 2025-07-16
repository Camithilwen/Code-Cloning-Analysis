/* 
 * Project: AtCoder Beginners Contest 105 A - AtCoder Crackers
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/16
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int n, k;

void solve() {
    
    int rem = n % k;
    if (rem == 0)
        printf("0\n");
    else
        printf("1\n");

}

int main() {

    scanf("%d", &n);
    scanf("%d", &k);

    solve();

}