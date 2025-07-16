#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;

vector <pair <int, int>> who[N];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  for (int a = -1000; a <= 1000; ++a) {
    for (int b = -1000; b <= 1000; ++b) {
      if (a * a + b * b < N) {
        who[a * a + b * b].push_back({a, b});
      }
    }
  }

  int n, d1, d2;
  cin >> n >> d1 >> d2;
  int m = 2 * n;
  vector <vector <int>> g1(m * m), g2(m * m);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      for (auto p : who[d1]) {
        int x = i + p.first, y = j + p.second;
        if (0 <= x && x < m && 0 <= y && y < m) {
          g1[i * m + j].push_back(x * m + y);
        }
      }
      for (auto p : who[d2]) {
        int x = i + p.first, y = j + p.second;
        if (0 <= x && x < m && 0 <= y && y < m) {
          g2[i * m + j].push_back(x * m + y);
        }
      }
    }
  }
  vector <int> c1(m * m, -1), c2(m * m, -1);
  function <void(int, vector <vector <int>> &, vector <int> &)> dfs = [&] (int u, vector <vector <int>> &g, vector <int> &c) {
    for (auto v : g[u]) {
      if (c[v] == -1) {
        c[v] = c[u] ^ 1;
        dfs(v, g, c);
      }
    }
  };
  for (int i = 0; i < m * m; ++i) {
    if (c1[i] == -1) {
      c1[i] = 0;
      dfs(i, g1, c1);
    }
  }
  for (int i = 0; i < m * m; ++i) {
    if (c2[i] == -1) {
      c2[i] = 0;
      dfs(i, g2, c2);
    }
  }
  for (int t1 = 0; t1 < 2; ++t1) {
    for (int t2 = 0; t2 < 2; ++t2) {
      vector <pair <int, int>> have;
      for (int i = 0; i < m * m; ++i) {
        if (c1[i] == t1 && c2[i] == t2) {
          have.push_back({i / m, i % m});
        }
      }
      if ((int)have.size() >= n * n) {
        for (int i = 0; i < n * n; ++i) {
          cout << have[i].first << ' ' << have[i].second << '\n';
        }
        return 0;
      }
    }
  }
}

