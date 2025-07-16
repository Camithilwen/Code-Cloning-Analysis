#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

#define vt          vector
#define sz(x)       (int)(x).size()
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

const int maxn = 80, maxk = 1 << 14, init = 1 << 13;
bool dp[maxn][maxn][maxk];
int a[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            a[i][j] = abs(t - a[i][j]);
        }
    }

    dp[0][0][init - **a] = dp[0][0][init + **a] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int &d = a[i][j];
            for (int k = d; k < maxk - d; k++) {
                bool &cur = dp[i][j][k];
                if (i) {
                    auto &p = dp[i - 1][j];
                    if (p[k - d] || p[k + d]) cur = true;
                }
                if (j) {
                    auto &p = dp[i][j - 1];
                    if (p[k - d] || p[k + d]) cur = true;
                }
            }
        }
    }

    int ans = 1 << 30;
    for (int i = 0; i < maxk; i++) {
        if (dp[n - 1][m - 1][i]) ans = min(ans, abs(i - init));
    }
    cout << ans;
}
