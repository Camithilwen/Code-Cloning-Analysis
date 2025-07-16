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

ll mPrime = int(1e9) + 7;
ll bN, bX;
vector<ll> bS;
vector<ll> facts;
vector<ll> invFacts;
vector<int> tbl;
vector<int> low;  // low[y] == #{ i | s[i] <= y }

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


ll tight(ll);

ll loose(ll y, ll len) {
  ll result = mMul(tight(y), mMul(facts.at(len), invFacts.at(low.at(y))));
  DLOG("loose(%lld, %lld) = %lld\n", y, len, result);
  return result;
}

ll tight(ll y) {
  if (tbl.at(y) >= 0)  return tbl.at(y);
  ll len = low.at(y);
  if (len == 0)  return y;
  ll result = 0;
  for (ll i = 0; i < len; i++) {
    ll z = y % bS.at(i);
    result = mAdd(result, loose(z, len-1));
  }
  tbl.at(y) = result;
  DLOG("tight(%lld) = %lld\n", y, result);
  return result;
}

int main() {
  cin >> bN >> bX;
  bS.resize(bN);
  for (ll i = 0; i < bN; i++) {
    cin >> bS.at(i);
  }
  facts.resize(bN+1);
  invFacts.resize(bN+1);
  facts.at(0) = invFacts.at(0) = 1;
  for (ll i = 1; i <= bN; i++) {
    facts.at(i) = mMul(i, facts.at(i-1));
    invFacts.at(i) = mInv(facts.at(i));
  }
  sort(bS.begin(), bS.end());

  low.resize(bX+1);
  ll idx = 0;
  for (ll i = 0; i < bX+1; i++) {
    if (idx < (ll) bS.size() && bS.at(idx) == i)  idx++;
    low.at(i) = idx;
  }

  tbl.resize(bX+1, -1);
  ll ans = loose(bX, bS.size());
  cout << ans << endl;

  return 0;
}

