#include <bits/stdc++.h>
#define range(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
using namespace std;

int main() {
    string s;
    cin >> s;

    vector <pair <char, int>> ci;
    rep (i, s.size()) {
        if ((i == 0) || (i != 0 && s[i] != s[i - 1])) ci.emplace_back(s[i], 1);
        else ci.back().second ++;
    }

    int ans = 0;
    rep (i, (int)ci.size() - 2) {
        if (ci[i].first == 'J' && ci[i + 1].first == 'O' && ci[i + 2].first == 'I') {
            if (ci[i].second >= ci[i + 1].second && ci[i + 1].second <= ci[i + 2].second) {
                ans = max(ans, min({ci[i].second, ci[i + 1].second, ci[i + 2].second}));
            }
        }
    }
    cout << ans << endl;

    return 0;
}
