#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = INT_MAX;
const int MOD = 1000000007;
const long long INF = LLONG_MAX;

// -------------------------------------------------------

int sx, sy, tx, ty;

int main() {
  cin >> sx >> sy >> tx >> ty;
  int dx = tx - sx;
  int dy = ty - sy;
  rep(i, 0, dy) { cout << "U"; }
  rep(i, 0, dx) { cout << "R"; }
  rep(i, 0, dy) { cout << "D"; }
  rep(i, 0, dx) { cout << "L"; }
  cout << "L";
  rep(i, 0, dy + 1) { cout << "U"; }
  rep(i, 0, dx + 1) { cout << "R"; }
  cout << "D";
  cout << "R";
  rep(i, 0, dy + 1) { cout << "D"; }
  rep(i, 0, dx + 1) { cout << "L"; }
  cout << "U";
}
