#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && a != c) {
        cout << "Yes" << "\n";
    } else if (c == b && b != a) {
        cout << "Yes" << "\n";
    } else if (c == a && b != a) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }


}













