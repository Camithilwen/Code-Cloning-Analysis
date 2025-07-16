#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

vector<vector<int>> G;
vector<int> colors;

bool dfs(int v, int color = 0) {
  colors[v] = color;

  for(auto u : G[v]) {
    if (colors[u] != -1) {
      if (colors[u] == color) return false;
      continue;
    }
    if(!dfs(u, 1 - color)) return false;
  }
  return true;
}

int main() {
  ll n, m;
  cin >> n >> m;
  colors.assign(n, -1);
  G.resize(n);

  for(int i = 0; i < m; ++i) {
    int a , b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bool bipartite = true;
  if(!dfs(0)) bipartite = false;

  if (bipartite) {
    ll w = 0, b = 0;
    for(int i = 0; i < n; ++i) {
      b += colors[i];
    }
    w = n - b;
    cout << w*b-m << endl;
  } else {
    cout << n*(n-1)/2-m << endl;
  }
  return 0;
}