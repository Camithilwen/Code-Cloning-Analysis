#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    string s;
    cin >> s;
    for (size_t i = 0; i < s.size() - 1; i++) {
        if (s.at(i) == 'A' && s.at(i + 1) == 'C') {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}