#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

const ll INF = 1LL << 50;

struct UnionFind {
  vll par;
  vll wcnt;
  vll bcnt;
  ll cnt;
  UnionFind(ll N, vector<string>& mp) : par(N), wcnt(N, 0), bcnt(N, 0), cnt(N) {
    for (ll i = 0; i < N; i++) {
      par[i] = i;
      ll w = (ll)mp[0].size();
      if (mp[i / w][i % w] == '.')
        wcnt[i] = 1;
      else
        bcnt[i] = 1;
    }
  }

  ll find(ll x) { return par[x] == x ? x : par[x] = find(par[x]); }

  bool same(ll x, ll y) { return find(x) == find(y); }

  ll get_wcnt(ll x) { return wcnt[find(x)]; }
  ll get_bcnt(ll x) { return bcnt[find(x)]; }

  void unite(ll x, ll y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    ll sizex = wcnt[x] + bcnt[x];
    ll sizey = wcnt[y] + bcnt[y];
    if (sizex < sizey) swap(x, y);
    par[y] = x;
    wcnt[x] += wcnt[y];
    bcnt[x] += bcnt[y];
    cnt--;
  }

  ll count() const { return cnt; }
};

int main() {
  ll x, y;
  cin >> x >> y;
  ll ans = 0;
  if (x == 1)
    ans += 300000;
  else if (x == 2)
    ans += 200000;
  else if (x == 3)
    ans += 100000;

  if (y == 1)
    ans += 300000;
  else if (y == 2)
    ans += 200000;
  else if (y == 3)
    ans += 100000;

  if (x == 1 && y == 1) ans += 400000;

  cout << ans << endl;

  return 0;
}
