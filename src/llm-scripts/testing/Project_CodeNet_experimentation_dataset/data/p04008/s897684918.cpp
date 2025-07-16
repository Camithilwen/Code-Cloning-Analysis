#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, k, ans = 0, prt[N];
vector<int> g[N];

int dfs(int u, int fa) {
  int res = 0;
  for (auto v : g[u]) {
    res = max(res, dfs(v, u));
  }
  if (res == k - 1 && fa != 1) {
    res = -1;
    ans++;
  }
  return res + 1;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &prt[i]);
    if (i > 1) {
      g[prt[i]].push_back(i);
    }
  }
  if (prt[1] != 1) {
    ans ++;
    prt[1] = 1;
  }
  dfs(1, 1);
  printf("%d\n", ans);
  return 0;
}