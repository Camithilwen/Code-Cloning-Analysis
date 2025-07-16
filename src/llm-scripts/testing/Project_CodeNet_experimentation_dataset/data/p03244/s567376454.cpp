#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n;
  cin >> n;
  map<ll, ll> m1, m2;
  set<P, greater<P>> st1, st2;
  rep(i, n) {
    ll v;
    cin >> v;
    if(i % 2)
      m1[v]++;
    else
      m2[v]++;
  }
  m1[0] = m2[0] = 0;
  for(auto v : m1) st1.emplace(v.second, v.first);
  for(auto v : m2) st2.emplace(v.second, v.first);
  auto it = st1.begin();
  P a = *it;
  ++it;
  P b = *it;
  it = st2.begin();
  P c = *it;
  ++it;
  P d = *it;
  ll ans;
  if(a.second == c.second) {
    ll n1 = n - a.first - d.first;
    ll n2 = n - b.first - c.first;
    ans = min(n1, n2);
  } else
    ans = n - a.first - c.first;
  cout << ans << endl;
}