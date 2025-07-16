#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#define NMAX 200001

int a[NMAX];
int imos[NMAX];

void reset(int n) {
    for(int i = 0; i < n; i++) imos[i] = 0;
}

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

int min(int a, int b) {
    if(a > b) return b;
    else return a;
}

int get_int() {
    int res = 0;
    char c = getchar();
    while(c != EOF && c != ' ' && c != '\n') {
        res *= 10;
        res += c - '0';
        c = getchar();
    }
    return res;
}

void put_int(int n) {
    char c[30];
    int sz = 0;
    c[sz++] = (n % 10) + '0';
    n /= 10;
    while(n > 0) {
        c[sz++] = (n % 10) + '0';
        n /= 10;
    }
    for(int i = sz-1; i >= 0; i--) {
        putchar(c[i]);
    }
    putchar('\n');
}

int main(){

    int n, k;
    n = get_int();
    k = get_int();
    for(int i = 0; i < n; i++) a[i] = get_int();

    for(int itr = 0; itr < k; itr++) {
        int f = 0;
        reset(n+1);
        for(int i = 0; i < n; i++){
            imos[max(0, i - a[i])]++;
            imos[min(n, i + a[i] + 1)]--;
        }
        int acc = 0;
        for(int i = 0; i < n; i++){
            acc += imos[i];
            a[i] = acc;
        }
        int sum = 0;
        for(int i = 0; i < n; i++) sum += a[i];
        if(sum == n * n) break;
    }

    for(int i = 0; i < n; i++) put_int(a[i]);
    return 0;
}
