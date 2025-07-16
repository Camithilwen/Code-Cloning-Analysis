#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long k;
    cin >> k;
    long q = k / 50, r = k % 50;
    cout << 50 << '\n';
    for (long i=0; i<50; i++) 
        cout << q + i - r + (i < r ? 51 : 0) << (i < 49 ? ' ' : '\n');
    return 0;
}