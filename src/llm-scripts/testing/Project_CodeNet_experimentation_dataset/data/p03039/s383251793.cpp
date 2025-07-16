#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

const ll MAX = 200200, MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];
// 前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
// 二項係数の計算
ll COM(int n, int k){
    if (n < 0 || k < 0 || n < k) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
    ll n, m, k; cin >> n >> m >> k;
    COMinit();
    ll ans = 0;
    rep(i,n) ans += i*((n-i)*m*m % MOD) * COM(n*m-2, k-2) % MOD, ans %= MOD;
    rep(i,m) ans += i*((m-i)*n*n % MOD) * COM(n*m-2, k-2) % MOD, ans %= MOD;
    cout << ans << endl;
    return 0;
}