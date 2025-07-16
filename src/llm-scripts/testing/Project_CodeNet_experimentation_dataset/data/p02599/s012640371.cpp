#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e5 + 55;

int fen[N];

void upd(int x, int y) {
  while (x < N) {
    fen[x] += y;
    x |= (x + 1);
  }
}

int get(int x) {
  int res = 0;
  while (x >= 0) {
    res += fen[x];
    x = (x & (x + 1)) - 1;
  }
  return res;
}

int res[N];
vector<pair<int, int>> vec[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    --c[i];
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    --l; --r;
    vec[r].emplace_back(l, i);
  }
  vector<int> last(n, -1);
  for (int i = 0; i < n; i++) {
    if (last[c[i]] != -1) {
      upd(last[c[i]], -1);
    }
    last[c[i]] = i;
    upd(i, 1);
    for (auto u : vec[i]) {
      res[u.second] = get(i) - get(u.first - 1);
    }
  }
  for (int i = 0; i < q; i++) {
    cout << res[i] << '\n';
  }
  return 0;
}
