#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int s[10001];

void sieve() {
    for(int i = 0; i < 10001; i++) s[i] = 1;
    s[0] = s[1] = 0;

    for(int i = 2; i <= sqrt(10001); i++) {
        if(s[i]) {
            for(int j = i * i; j < 10001; j += i) {
                s[j] = 0;
            }
        }
    }
}

int main() {
    sieve();
    int n;
    while(~scanf("%d", &n)) {
        if(n == 0) break;
        for(int i = n; i >= 2; i--) {
            if(s[i] && s[i - 2]) {
                printf("%d %d\n", i - 2, i);
                goto end;
            }
        }
        end:;
    }
}