#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 組合せを素数で割った値を求める
const int MAX = 510000;
const int MOD = 1e9 + 7;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, m, k;
  cin >> n >> m >> k;
  
  COMinit();
  
  ll ans = 0;
  for(int i = 1; i <= m - 1; i++){
    ll keep = (((i * n * n) % MOD) * (m - i)) % MOD;
    keep *= COM(n * m - 2, k - 2);
    keep %= MOD;
    ans += keep;
    ans %= MOD;
  }
  for(int i = 1; i <= n - 1; i++){
    ll keep = (((i * m * m) % MOD) * (n - i)) % MOD;
    keep *= COM(n * m - 2, k - 2);
    keep %= MOD;
    ans += keep;
    ans %= MOD;
  }
  
  cout << ans << '\n';
}