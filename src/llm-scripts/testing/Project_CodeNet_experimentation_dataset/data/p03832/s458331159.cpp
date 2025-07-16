#include <iostream>
using namespace std;

//const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;

#define REP(i,n) for (int i = 0; i < (n); i++)
#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second

ll n,a,b,c,d;
ll dp[1010][1010];
ll K[1010];
ll cc[1010][1010];
ll inv[1010];

ll mul(ll _a, ll _b) {
  if (_b == 0) return 1LL;
  if (_b == 1) return _a;
  ll ans = mul(_a, _b/2);
  ans *= ans;
  ans %= MOD;
  if (_b&1) ans *= _a;
  return ans % MOD;
}

ll C(ll _n, ll _k) {
  if (cc[_n][_k] != 0LL) return cc[_n][_k];
  if (_n == _k) return cc[_n][_k] = 1;
  return cc[_n][_k] = (K[_n] * ((inv[_k] * inv[_n-_k]) % MOD)) % MOD;
}

ll get(ll groups, ll mem, ll from) {
  ll ans = 1;

  REP(i,groups) {
    ans *= C(from, mem);
    ans %= MOD;
    from -= mem;
  }

  return (ans * inv[groups]) % MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> a >> b >> c >> d;
  dp[0][0] = 1;

  K[1] = 1;
  inv[1] = 1;
  for (ll i = 2; i <= n; i++) {
    K[i] = K[i-1]*i;
    K[i] %= MOD;
    inv[i] = mul(K[i], MOD-2);
  }

  for (ll i = 1; i <= b; i++) {
    if (i < a) {
      dp[i][0] += dp[i-1][0];
      dp[i][0] %= MOD;
      continue;
    }
    REP(j,n+1) {
      dp[i][j] += dp[i-1][j];
      dp[i][j] %= MOD;
      ll k = c;
      while (k <= d && j + k * i <= n) {
        dp[i][j+k*i] += dp[i-1][j] * get(k, i, n-j);
        dp[i][j+k*i] %= MOD;
        k++;
      }
    }
  }
  cout << dp[b][n] << endl;
  return 0;
}
