#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int d, t, s;
    cin >> d >> t >> s;
    string ans = "Yes";
    if (s * t < d) ans = "No";
    cout << ans << endl;
}