#include <bits/stdc++.h>

using namespace std;


int main() {
    int a, b, k;
    cin >> a >> b >> k;
    for(int i = 0; i < k; i++) {
        if(i % 2 == 0) {
            if(a % 2 != 0) {
                a--;
            }
            int h = a / 2;
            a = h;
            b += h;
        } else {
            if(b % 2 != 0) {
                b--; 
            }
            int h = b / 2;
            b = h;
            a += h;
        }
    }
    cout << a << " " << b << "\n";
    return 0;
}