#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#define DEBUG 0

#if DEBUG
  #define DLOG(...) fprintf(stderr, __VA_ARGS__)
#else
  #define DLOG(...)
#endif

void debug(auto f) {
#if DEBUG
  f();
#endif
}

ll mPrime = 1000*1000*1000 + 7;
ll n, x;
vector<ll> s;
vector<ll> facts;
vector<ll> invFacts;
vector<int> tbl;

ll mAdd(ll x, ll y) {
  ll z = x + y;
  if (z < mPrime)  return z;
  else             return (z - mPrime);
}

ll mSub(ll x, ll y) {
  ll z = x - y;
  if (z >= 0)  return z;
  else         return (z + mPrime);
}

ll mMul(ll x, ll y) {
  return (x * y) % mPrime;
}

ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

ll mInv(ll x) {
  ll s, t;
  eGCD(x, mPrime, s, t);
  return s < 0 ? s + mPrime : s;
}


int main() {
  cin >> n >> x;
  s.resize(n);
  for (ll i = 0; i < n; i++) {
    cin >> s.at(i);
  }
  facts.resize(n+1);
  invFacts.resize(n+1);
  facts.at(0) = invFacts.at(0) = 1;
  for (ll i = 1; i <= n; i++) {
    facts.at(i) = mMul(i, facts.at(i-1));
    invFacts.at(i) = mInv(facts.at(i));
  }
  sort(s.begin(), s.end());

  tbl.resize(x+1, 0);
  tbl.at(x) = 1;
    
  ll lim = x;
  for (ll k = n; k >= 1; k--) {
    ll newLim = 0;
    for (ll r = 1; r <= lim; r++) {
      ll weight = tbl.at(r);
      if (weight == 0)  continue;
      newLim = r;
      ll rem = k;
      for (ll t : s) {
	if (r < t)  break;
	rem--;
	ll newR = r % t;
	tbl.at(newR) = mAdd(tbl.at(newR), weight);
      }
      tbl.at(r) = mMul(tbl.at(r), rem);
    }
    lim = newLim;
  }
  ll ans = 0;
  for (ll r = 1; r <= lim; r++) {
    ans = mAdd(ans, mMul(tbl.at(r), r));
  }
  cout << ans << endl;

  return 0;
}

