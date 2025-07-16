#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) {
        cout << 2*a-1 << "\n";
    }
    else if (b > a) {
        cout << 2*b-1 << "\n";
    }
    else {
        cout << a + b << "\n";
    }
    return 0;
}