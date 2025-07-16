#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll H, W;
ll A[85][85], B[85][85];
ll AB[85][85];

const ll D = 160 * 80 + 10; // あり得る長さ
const ll D2 = D * 2; // あり得る値の範囲
typedef bitset<D2> bs;

// [r][c] にきたときに、この値はあり得るか。0 or 1
bs dp[85][85];

int main() {
    cin >> H >> W;
    rep(i, H)rep(j, W) cin >> A[i][j];
    rep(i, H)rep(j, W) cin >> B[i][j];

    rep(i, H)rep(j, W) AB[i][j] = abs(A[i][j] - B[i][j]);

    dp[0][0][D - AB[0][0]] = 1;
    dp[0][0][D + AB[0][0]] = 1;

    rep(i, H)rep(j, W) {
        if (i) {
            // たす
            dp[i][j] |= dp[i - 1][j] << AB[i][j];
            // 引く
            dp[i][j] |= dp[i - 1][j] >> AB[i][j];
        }

        if (j) {
            // たす
            dp[i][j] |= dp[i][j - 1] << AB[i][j];
            // 引く
            dp[i][j] |= dp[i][j - 1] >> AB[i][j];
        }
    }

    // 答えを求める D の分を戻す
    ll ans = INF;
    rep(i, D2) {
        if (dp[H - 1][W - 1][i]) ans = min(ans, abs(i - D));
    }
    cout << ans << endl;
}