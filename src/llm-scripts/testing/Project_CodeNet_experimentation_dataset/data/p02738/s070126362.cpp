#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

ll fact[7000];
ll ifact[7000];

// a^-1 mod p
ll inv(ll a,ll p){
  return ( a == 1 ? 1 : (1 - p*inv(p%a,a)) / a + p );
}

ll comb(ll n, ll k, ll m) {
  return fact[n] * ifact[k] % m * ifact[n-k] % m;
}

ll pmod(ll x, ll i, ll m) {
  if (i == 0) return 1;
  if (i % 2 == 1) return pmod(x, i-1, m) * x % m;
  ll h = pmod(x, i/2, m);
  return h * h % m;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m;
  cin>>n>>m;
  fact[0] = 1;
  REP(i,7000-1) {
    fact[i+1] = (i+1) * fact[i] % m;
  }
  ifact[6999] = inv(fact[6999], m);
  REP(i,7000-1) {
    int j = 7000-i-1;
    ifact[j-1] = j * ifact[j] % m;
  }
  ll inv3 = inv(3, m);
  ll inv2 = inv(2, m);
  ll ans = 0;
  REP(i,n+1) {
    REP(j,n+1-i) {
      ll tmp = comb(3*n, 3*i, m);
      tmp *= fact[3*i] * ifact[i] % m;
      tmp %= m;
      tmp *= pmod(inv3, i, m);
      tmp %= m;
      ll rem = 3*n - 3*i;
      tmp *= comb(rem, 2*j, m);
      tmp %= m;
      tmp *= fact[2*j] * ifact[j] % m;
      tmp %= m;
      tmp *= pmod(inv2, j, m);
      tmp %= m;
      ans += tmp;
      ans %= m;
    }
  }
  cout << ans << endl;
  return 0;
}
