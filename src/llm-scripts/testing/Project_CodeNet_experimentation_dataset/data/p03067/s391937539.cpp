#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if ((A - C) * (B - C) < 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
