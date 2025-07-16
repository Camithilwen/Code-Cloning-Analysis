#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    bool ok = true;
    if (n % 2) ok = false;
    else {
        REP(i, n) {
            if (i % 2) {
                if (s[i] != 'i')
                    ok = false;
            } else {
                if (s[i] != 'h')
                    ok = false;
            }
        }
    }

    if (ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    return 0;
}