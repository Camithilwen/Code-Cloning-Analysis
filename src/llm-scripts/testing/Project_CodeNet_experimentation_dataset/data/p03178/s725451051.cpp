#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int mod = 1e+9 + 7;
/* global variables */
/* funciton */
/* main */
int main() {
    string S;
    int D;
    cin >> S >> D;
    vector<int> a(S.size());
    for (int i = 0; i < S.size(); i++) a[i] = S[i] - '0';

    // dp[i][j][0] i桁目まで使って, mod D = j, 現時点でSよりも数字が小さいことが確定している
    // dp[i][j][1] i桁目まで使って, mod D = j, 現時点でSと同じ数字 -> これから同じ or 小さい
    // transition)
    // dp[i+1][j+(num = a[i]) mod D][1] += dp[i][j][1]
    // dp[i+1][j+(num < a[i]) mod D][0] += dp[i][j][1]
    // dp[i+1][j+(0<= num <= 9) mod D][0] += dp[i][j][0]
    // init
    vector<vector<vector<ll>>> dp(a.size() + 1, vector<vector<ll>>(D, vector<ll>(2)));
    dp[0][0][1] = 1;
    // calc
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < D; j++) {
            for (int num = 0; num <= 9; num++) {
                int neJ = (j + num) % D;
                if (num == a[i]) {
                    dp[i+1][neJ][1] += dp[i][j][1];
                    dp[i+1][neJ][1] %= mod;
                }
                if (num < a[i]) {
                    dp[i+1][neJ][0] += dp[i][j][1];
                    dp[i+1][neJ][1] %= mod;
                }
                dp[i+1][neJ][0] += dp[i][j][0];
                dp[i+1][neJ][0] %= mod;
            }
        }
    }
    // ans = (mod D == j)の個数
    // 答えに0が含まれるので-1する
    ll ans = (dp[a.size()][0][1] + dp[a.size()][0][0] - 1 + mod) % mod;
    cout << ans << '\n';
}