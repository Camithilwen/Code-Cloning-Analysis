#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD (long long)(1e9+7)
#define INF (1LL<<60)
#define rep(i,n) for(ll i = 0; i < (n); i++)
#define rep1(i,n) for(ll i = 1; i <= (n); i++)

template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}


// 最大公約数
ll gcd(ll a, ll b)
{
  if(b == 0) return a;
  return gcd(b, a % b);
}

// mod m におけるa の逆元
ll modinv(ll a, ll m) {
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    a -= t * b; swap(a, b);
    u -= t * v; swap(u, v);
  }
  u %= m;
  if (u < 0) u += m;
  return u;
}

// 素因数分解
vector<pair<ll, ll>> prim;
void pf(ll n)
{
  ll s = sqrt(n);
  ll r = 0;
  for(ll i = 2; i <= s; i++) {
    if((n % i) == 0) {
      r = 0;
      do {
	r++;
	n = n / i;
      } while((n % i) == 0);
      prim.push_back({i, r});
    }
  }
  if(n > s) {
    prim.push_back({n, 1});
  }
}



void solve()
{
  ll D, G; cin >> D >> G;
  vector<ll> p(D), c(D); rep(i, D) cin >> p[i] >> c[i];
  vector<ll> cp(D); rep(i, D) cp[i] = (i + 1) * p[i] * 100 + c[i];
  rep(i, D) cerr << i << " cp:" << cp[i] << endl;
  ll pmin = -1;
  for(ll i = 0; i < (1<<D); i++) {
    ll ttl = 0;
    ll nop = 0;
    for(ll j = 0; j < D; j++) {
      if(i & 1<<j) {
	ttl += cp[j];
	nop += p[j];
      }
    }
    cerr << i << " ttl:" << ttl << endl;
    if(ttl < G) {
      ll mxp ;
      for(mxp = D - 1; mxp >=0 && ((i & 1 << mxp) !=0); mxp--) ;
      cerr << " mxp:" << mxp << endl;
      rep(j, p[mxp] - 1) {
	ttl += (mxp + 1) * 100;
	nop ++;
	if(ttl >= G) break;
      }
    }
    cerr << " nop:" << nop << endl;
    if(ttl >= G &&(pmin < 0 || nop < pmin)) pmin = nop;
  }
    
  cout << pmin << endl;

}


int main(void)
{
  // ll t; cin >> t; rep(i, t)
  solve();
}
