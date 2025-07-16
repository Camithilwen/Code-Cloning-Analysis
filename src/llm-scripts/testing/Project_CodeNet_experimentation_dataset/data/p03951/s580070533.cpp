#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    int index = -1;
    REP(i, n) {
        if (s.substr(i, n - i) == t.substr(0, n - i)) {
            index = i;
            break ;
        }
    }

    if (index == -1) cout << s.size() + t.size() << '\n';
    else cout << n + index << '\n';
    return 0;
}
