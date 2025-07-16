#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int l;
    long stocks = 1000;

    for (long long i = 1; i*i <= n; i++) {
        if (n % i != 0) continue;
        l = log10(n/i) + 1;
        if (l < stocks) stocks = l;
        
    }

    cout << stocks << endl;

}