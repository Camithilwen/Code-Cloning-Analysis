// 2020-08-26 16:05:35
// clang-format off
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
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
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

// clang-format on
void answer() {
  int n;
  cin >> n;
  vector<int> p(55555 + 55, 1), ans;
  p[0] = p[1] = 0;
  REP(i, 2, 55555 + 5) if (p[i]) {
    for (int j = 2 * i; j < 55555 + 5; j += i) p[j] = 0;
    if (i % 5 == 1) {
      ans.push_back(i);
      if (ans.size() == n) break;
    }
  }
  rep(i, ans.size()) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}