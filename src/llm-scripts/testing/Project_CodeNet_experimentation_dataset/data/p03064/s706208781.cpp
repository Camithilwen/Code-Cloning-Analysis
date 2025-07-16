#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 998244353;
ll x[301];
int N;

ll dp1[301][100001]; // 3-color
ll dp2[301][100001]; // 2-color


int main() {
    cin >> N;
    ll S = 0;
    ll ans = 1;
    for(int i = 0; i < N; i++) {
        cin >> x[i];
        S += x[i];
        ans *= 3;
        ans %= MOD;
    }

    dp1[0][0] = dp2[0][0] = 1;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 100001; j++) {
            dp1[i+1][j+x[i]] += dp1[i][j]; // 色を塗り替えても同じ．
            dp1[i+1][j+x[i]] %= MOD;
            dp1[i+1][j] += (2*dp1[i][j])%MOD;
            dp1[i+1][j] %= MOD;

            dp2[i+1][j+x[i]] += dp2[i][j];
            dp2[i+1][j+x[i]] %= MOD;

            dp2[i+1][j] += dp2[i][j];
            dp2[i+1][j] %= MOD;
        }
    }

    for(int i = (S+1)/2; i <= S; i++) {
        ans -= (dp1[N][i] * 3) % MOD; // 条件(S/2 > i)を満たさない数を引く
        ans %= MOD;
    }

    if(S%2 == 0) {
        ans += (dp2[N][S/2]*3 % MOD);
    }

    ans += MOD;
    ans %= MOD;
    cout << ans << endl;

}