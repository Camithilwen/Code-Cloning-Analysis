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
  map<char, vector<P>> mp;
  rep(i, n) {
    ll x, y;
    char c;
    cin >> x >> y >> c;
    mp[c].push_back({x, y});
  }
  ll ans = 1e18;
  map<ll, set<ll>> ds, ls;
  for(auto p : mp['D']) ds[p.first].insert(p.second);
  for(auto p : mp['U']) {
    ll x = p.first;
    ll y = p.second;
    auto in = ds[x].lower_bound(y);
    if(in == end(ds[x])) continue;
    ll now = (*in - y) * 5;
    ans = min(ans, now);
  }
  for(auto p : mp['L']) ls[p.second].insert(p.first);
  for(auto p : mp['R']) {
    ll x = p.first;
    ll y = p.second;
    auto in = ls[y].lower_bound(x);
    if(in == end(ls[y])) continue;
    ll now = (*in - x) * 5;
    ans = min(ans, now);
  }

  map<ll, set<ll>> u, d;
  for(auto p : mp['U']) u[p.first + p.second].insert(p.first);
  for(auto p : mp['D']) d[p.first - p.second].insert(p.first);
  for(auto p : mp['R']) {
    ll x = p.first;
    ll y = p.second;
    auto in = u[x + y].lower_bound(x);
    ll now;
    if(in != end(u[x + y])) {
      now = (*in - x) * 10;
      ans = min(ans, now);
    }
    in = d[x - y].lower_bound(x);
    if(in != end(d[x - y])) {
      now = (*in - x) * 10;
      ans = min(ans, now);
    }
  }

  u.clear();
  d.clear();
  for(auto p : mp['U']) u[p.first - p.second].insert(p.first);
  for(auto p : mp['D']) d[p.first + p.second].insert(p.first);
  for(auto p : mp['L']) {
    ll x = p.first;
    ll y = p.second;
    auto in = u[x - y].upper_bound(x);
    ll now;
    if(in != begin(u[x - y])) {
      in--;
      now = (x - *in) * 10;
      ans = min(ans, now);
    }
    in = d[x + y].upper_bound(x);
    if(in != begin(d[x + y])) {
      in--;
      now = (x - *in) * 10;
      ans = min(ans, now);
    }
  }

  if(ans == 1e18)
    cout << "SAFE" << endl;
  else
    cout << ans << endl;
}