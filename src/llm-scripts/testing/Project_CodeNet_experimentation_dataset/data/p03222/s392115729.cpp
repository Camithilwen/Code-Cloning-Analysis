#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;
 
#define rp(i, k, n) for (int i = k; i < n; i++)
using ll = long long;
using ld = double;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    // dp[i][j]...i列目が終わった時にj行目にいるようなあみだくじの作り方
    vector<vector<ll>> dp(h+10, vector<ll>(w+10));

    vector<ll> com(w+10);
    com[0] = 1ll;
    com[1] = 2ll;
    rp(i, 2, w){
        com[i] = com[i-1] + com[i-2];
        com[i] %= MOD;
    }

    dp[0][1] = 1ll;
    rp(i, 0, h) {
        rp(j, 1, w+1) {
            if(j < w) {
                int right = max(0, w-j-2);
                int left = max(0, j-2);
                dp[i+1][j+1] += dp[i][j] * com[right] * com[left] % MOD; dp[i+1][j+1] %= MOD;
            }
            if(j > 1) {
                int right = max(0, w-j-1);
                int left = max(0, j-3);
                dp[i+1][j-1] += dp[i][j] * com[right] * com[left] % MOD; dp[i+1][j-1] %= MOD;
            }
            int right = max(0, w-j-1);
            int left = max(0, j-2);
            dp[i+1][j] += dp[i][j] * com[right] * com[left] % MOD; dp[i+1][j] %= MOD;
        }
    }
    // rp(i, 0, h) {
    //     rp(j, 1, w+1) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[h][k] << endl;
    return 0;

}
