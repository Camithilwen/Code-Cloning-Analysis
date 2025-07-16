#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;
// MAX int 2,147,483,647 -> 10桁
// MAX ll 9,223,372,036,854,775,807 -> 19桁
// MAX O(n) 10^8 -> 8回
// double pi = M_PI or acos(-1)
// printf("%.10f\n", ans);

int g[15][15];

int main() {
    int n;
    cin >> n;
    rep(i, n) rep(j, n) g[i][j] = -1;
    rep(i, n) {
        int m;
        cin >> m;
        rep(j, m) {
            int a, x;
            cin >> a >> x;
            --a;
            g[i][a] = x;
        }
    }
    int ans = 0;
    rep(i, 1 << n) {
        vector<int> d(n);
        rep(j, n) if(i >> j & 1) {
            d[j] = 1;
        }
        bool ok = true;
        rep(j, n) {
            if(d[j]) {
                rep(k, n) {
                    if (g[j][k] == -1) continue;
                    if (g[j][k] != d[k]) ok = false;
                }
            }
        }
        if (ok) ans = max(ans, __builtin_popcount(i));
    }
    cout << ans << endl;
    return 0;
}
