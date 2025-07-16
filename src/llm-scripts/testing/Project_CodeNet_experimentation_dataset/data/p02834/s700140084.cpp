#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

vector<int> G[200005];
int aoki_d[200005], takahashi_d[200005];
bool is_end[200005];

void dfs(int u, bool is_aoki, int p=-1) {
  for (int v : G[u]) {
    if (v == p) continue;
    if (is_aoki) aoki_d[v] = aoki_d[u] + 1;
    else takahashi_d[v] = takahashi_d[u] + 1;
    dfs(v, is_aoki, u);
  }
  is_end[u] = G[u].size() == 1;
}

int main() {
  int n, u, v;
  cin >> n >> u >> v;
  --u; --v;
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(u, false);
  dfs(v, true);
  int ans = 0;
  rep(i, n) {
    if (takahashi_d[i] <= aoki_d[i] && !is_end[i]) {
      ans = max(ans, aoki_d[i]);
    }
  }
  cout << ans << endl;
  return 0;
}