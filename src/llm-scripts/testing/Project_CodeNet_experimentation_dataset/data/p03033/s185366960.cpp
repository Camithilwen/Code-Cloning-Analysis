// 2020-07-15 23:41:12
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

void answer() {
  using Work = tuple<int, int, int>; // (x, s, t)
  using P = pair<int, int>;
  int n, q;
  cin >> n >> q;
  vector<Work> works(n);
  rep(i, n) {
    int s, t, x;
    cin >> s >> t >> x;
    works[i] = { x, s-x, t-x };
  }
  sort(ALL(works));
  set<P> ds;
  rep(i, q) {
    int d;
    cin >> d;
    ds.emplace(d, i);
  }
  vector<int> ans(q, -1);
  for(const auto& w : works) {
    int x, s, t;
    tie(x, s, t) = w;
    auto it = ds.lower_bound({ s, -1 });
    while(it != ds.end() && (*it).first < t) {
      int d, qi;
      tie(d, qi) = *it;
      ans[qi] = x;
      it++;
      ds.erase(prev(it));
    }
  }
  for(const auto x : ans) cout << x << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}