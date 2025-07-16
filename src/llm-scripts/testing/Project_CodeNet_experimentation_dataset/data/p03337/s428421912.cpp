#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y;
    cin >> x >> y;
    int add = x + y;
    int sub = x - y;
    int into = x * y;
    if (add >= sub && add >= into) {
        cout << add << "\n";
    } else if (sub >= add && sub >= into) {
        cout << sub << "\n";
    } else {
        cout << into << "\n";
    }

}










