#include <bits/stdc++.h>
using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    map<string, int> m{
        {"SUN", 7},
        {"MON", 6},
        {"TUE", 5},
        {"WED", 4},
        {"THU", 3},
        {"FRI", 2},
        {"SAT", 1}
    };

    string s;
    cin >> s;
    cout << m[s];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}
