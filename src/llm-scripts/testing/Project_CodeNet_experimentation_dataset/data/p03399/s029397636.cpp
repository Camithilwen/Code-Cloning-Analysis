#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <= b && c <= d) {
        cout << a + c << "\n";
    } else if (a <= b && c >= d) {
        cout << a + d << "\n";
    } else if (a >= b && c >= d) {
        cout << b + d << "\n";
    } else if (a >= b && c <= d) {
        cout << b + c << "\n";
    }


}













