#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

vvll mem;
int ng = 0;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll n, x, y, z; cin >> n >> x >> y >> z;

  ll MAX = 1ll << (x + y + z - 1);

  const ll NG_BITS = (1ll<<(x+y+z-1)) | (1ll<<(y+z-1)) | (1ll<<(z-1));

  vvll dp(n+1, vll(MAX, 0));
  dp[0][0] = 1;

  for(int i=0;i<n;++i) {
    for(ll j=1;j<=10;++j) {
      for(ll k=0;k<MAX;++k) {
        ll t = (k << j) | (1ll << (j - 1));

        if((NG_BITS & t) != NG_BITS) {
          t &= (MAX - 1);
          dp[i+1][t] += dp[i][k];
          dp[i+1][t] %= MOD;
        }
      }
    }
  }

  ll ans = 1;
  for(int i=0;i<n;++i) {
    ans *= 10;
    ans %= MOD;
  }

  for(int i=0;i<MAX;++i) {
    ans += MOD - dp[n][i];
    ans %= MOD;
  }
  cout << ans << endl;


}
