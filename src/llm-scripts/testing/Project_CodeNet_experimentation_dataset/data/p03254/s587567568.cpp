#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  sort(a.begin(), a.end());
  int res = 0;
  rep(i, n) {
    int aa = a.at(i);
    if (aa > x) {
      break;
    }
    if (i == n - 1) {
      if (aa != x) {
        break;
      }
    }
    x -= aa;
    res++;
  }
  cout << res << endl;
  return 0;
}
