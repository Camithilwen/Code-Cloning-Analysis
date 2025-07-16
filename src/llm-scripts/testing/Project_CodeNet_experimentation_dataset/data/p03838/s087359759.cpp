#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x, y, add = 1;
  cin >> x >> y;

  if ((x > 0 && y > 0) || (x < 0 && y < 0)) {
    if (x < y)
      add = 0;
    else
      add = 2;
  } else if (x == 0 && y > 0)
    add = 0;
  else if (x < 0 && y == 0)
    add = 0;

  cout << abs(abs(x) - abs(y)) + add << endl;
}
