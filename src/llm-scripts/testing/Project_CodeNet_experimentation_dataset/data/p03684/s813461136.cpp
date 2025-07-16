/**
 *    author:  tourist
 *    created: 17.11.2019 02:03:54       
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
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  vector<tuple<int, int, int>> e;
  auto Add = [&](int i, int j) { e.emplace_back(min(abs(x[i] - x[j]), abs(y[i] - y[j])), i, j); };
  {
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) { return x[i] < x[j]; });
    for (int i = 0; i < n - 1; i++) Add(order[i], order[i + 1]);
  }
  {
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) { return y[i] < y[j]; });
    for (int i = 0; i < n - 1; i++) Add(order[i], order[i + 1]);
  }
  sort(e.begin(), e.end());
  dsu d(n);
  long long ans = 0;
  for (auto& ee : e) {
    if (d.unite(get<1>(ee), get<2>(ee))) ans += get<0>(ee);
  }
  cout << ans << '\n';
  return 0;
}
