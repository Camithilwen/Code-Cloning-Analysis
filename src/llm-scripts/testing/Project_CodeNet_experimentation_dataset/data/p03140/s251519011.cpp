#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

const int a[3] = {0, 1, 2};
const int b[3] = {1, 2, 0};
const int c[3] = {2, 0, 1};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<char> > s(3, vector<char>(n));
    REP(i, 3) REP(j, n) cin >> s[i][j];

    int cnt = 0;
    REP(j, n) {
        REP(i, 3)
            if (s[a[i]][j] == s[b[i]][j] && s[b[i]][j] != s[c[i]][j])
                cnt++;
        if (s[0][j] != s[1][j] && s[0][j] != s[2][j] && s[1][j] != s[2][j])
            cnt += 2;
    }

    cout << cnt << '\n';
    return 0;
}