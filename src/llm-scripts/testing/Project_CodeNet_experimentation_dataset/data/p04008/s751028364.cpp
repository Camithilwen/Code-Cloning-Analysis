#include <bits/stdc++.h>

using namespace std;

int ans = 0;

int dfs(int v, int pv, int k, vector<vector<int>>& g) {
  int max_d = 0;
  for (int u : g[v]) {
    max_d = max(max_d, 1 + dfs(u, v, k, g));
  }
  if (max_d == k - 1 && v != 0) {
    ans += pv > 0;
    max_d = -1;
  }
  return max_d;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
    f[i]--;
  }
  ans = f[0] != 0;
  f[0] = -1;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    g[f[i]].push_back(i);
  }
  dfs(0, -1, k, g);
  /*
  for (int i = 0; i < n; i++) {
    cerr << i + 1 << " is connected with :";
    for (int j : g[i]) {
      cerr << ' ' << j + 1;
    }
    cerr << endl;
  }
  */
  cout << ans << '\n';
  return 0;
}