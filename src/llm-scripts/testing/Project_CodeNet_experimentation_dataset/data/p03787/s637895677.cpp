/**
 *    author:  tourist
 *    created: 22.01.2020 00:01:26       
**/
#include <bits/stdc++.h>

using namespace std;

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  dsu d(2 * n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    d.unite(x, y + n);
    d.unite(x + n, y);
  }
  vector<int> cnt(n, 0);
  for (int i = 0; i < n; i++) {
    cnt[d.get(i) % n] += 1;
  }
  long long iso = 0;
  long long bip = 0;
  long long non = 0;
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 1) {
      iso += 1;
    }
    if (cnt[i] > 1) {
      if (d.get(i) == d.get(i + n)) {
        non += 1;
      } else {
        bip += 1;
      }
    }
  }
  long long ans = iso * iso + iso * (n - iso) + (n - iso) * iso;
  ans += (non + bip) * (non + bip);
  ans += bip * bip;
  cout << ans << '\n';
  return 0;
}
