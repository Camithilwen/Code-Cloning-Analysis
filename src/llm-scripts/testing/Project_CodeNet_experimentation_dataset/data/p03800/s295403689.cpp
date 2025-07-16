#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    ll N;
    string S;
    cin >> N >> S;
    vector<string> ans = {"SS", "SW", "WS", "WW"};
    rep(i, 4) {
        rep(j, N) {
            if (ans[i][j + 1] == 'S') {
                if (S[j] == 'o') {
                    if (ans[i][j] == 'S') ans[i].push_back('S');
                    else ans[i].push_back('W');
                } else {
                    if (ans[i][j] == 'S') ans[i].push_back('W');
                    else ans[i].push_back('S');
                }
            } else {
                if (S[j] == 'o') {
                    if (ans[i][j] == 'S') ans[i].push_back('W');
                    else ans[i].push_back('S');
                } else {
                    if (ans[i][j] == 'S') ans[i].push_back('S');
                    else ans[i].push_back('W');
                }
            }
        }
        if (ans[i].substr(0, 2) == ans[i].substr(N, 2)) {
            cout << ans[i].substr(1, N) << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}