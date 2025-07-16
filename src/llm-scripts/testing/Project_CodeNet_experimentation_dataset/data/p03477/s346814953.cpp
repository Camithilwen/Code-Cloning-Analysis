#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a = a + b - c - d;
    if (a > 0) cout << "Left";
    if (a < 0) cout << "Right";
    if (a == 0) cout << "Balanced";
}