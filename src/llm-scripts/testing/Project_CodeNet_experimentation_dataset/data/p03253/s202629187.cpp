#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

map<ll, ll> prime_factor(ll n) {
      map< ll, ll > ret;
      for(ll i = 2; i * i <= n; i++) {
          while(n % i == 0) {
              ret[i]++;
              n /= i;
          }
      }
      if(n != 1) ret[n] = 1;
      return ret;
}

const int MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
ll COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(){
    ll n, m;
    cin >> n >> m;
    map<ll,ll> mp = prime_factor(m);
    COMinit();
    ll ans = 1;

    for(auto v : mp){
        ll p = v.second;
        ans *= COM(n+p-1, p);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}
