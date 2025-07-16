#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;


const int H = 105;
const int W = 10;
const int MOD = 1e9 + 7;
int h, w, k;
ll dp[H][W];
ll C[W];

void init() {
    C[1] = 2;
    int a = 1, b = 1;
    for (int i = 2; i < w; ++i) {
        int na = b;
        int nb = a + b;
        C[i] = na + nb;
        a = na;
        b = nb;
    }
}

ll cnt(int x) {
    if (x <= 0) return 1;
    return C[x];
}

int main() {
    cin >> h >> w >> k;
    init();
    for (int i = 0; i < w; ++i) {
        if (i == k - 1)
            dp[h][i] = 1;
        else
            dp[h][i] = 0;
    }
    // cout << dp[15][4] << endl;
    // dp[0][0] => dp[h - 1][k - 1]
    for (int i = h - 1; i >= 0; --i) {
        for (int j = 0; j < w; ++j) {
            dp[i][j] = dp[i + 1][j] * cnt(j - 1) % MOD * cnt(w - j - 2) % MOD; // 0 j 0
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i + 1][j - 1] * cnt(j - 2) % MOD * cnt(w - j - 2) % MOD) % MOD; // 1 j 0
            if (j < w - 1)
                dp[i][j] = (dp[i][j] + dp[i + 1][j + 1] * cnt(j - 1) % MOD * cnt(w - j - 3) % MOD) % MOD; // 0 j 1

            // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
