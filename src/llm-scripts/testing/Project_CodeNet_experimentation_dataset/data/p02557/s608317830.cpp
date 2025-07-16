// 2020-09-14 20:57:26
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
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];
  int d = 0;
  rep(ai, n) {
    auto itr = lower_bound(ALL(b), a[ai]);
    if (itr != b.end() && a[ai] == *itr) {
      chmax(d, ai - int(itr - b.begin() - 1));
    }
  }
  bool ok = true;
  rep(i, n) ok &= (a[i] != b[(n + i - d) % n]);
  if (ok) {
    cout << "Yes" << '\n';
    rep(i, n) {
      if (i) cout << ' ';
      cout << b[(n + i - d) % n];
    }
    cout << '\n';
  } else {
    cout << "No" << '\n';
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}