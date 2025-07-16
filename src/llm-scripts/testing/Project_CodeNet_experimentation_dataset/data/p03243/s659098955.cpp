#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n % 111 == 0) {
        cout << n << endl;
        return 0;
    }
    else {
        cout << 111 * ((n / 111)+1) << endl;
    }
}