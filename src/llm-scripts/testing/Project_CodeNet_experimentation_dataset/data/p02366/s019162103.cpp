#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mx = 100005;

int dtime = 0;
int n, m, par[mx], low[mx], start[mx];
vector<int> adj[mx], child[mx];
bool vis[mx];
set<int> art;

void dfs(int n, int p = -1) {
  //printf("DFS %d from %d\n", n, p);
  vis[n] = true;
  par[n] = p;
  child[p].pb(n);
  start[n] = dtime++;
  low[n] = start[n];
  
  for (int h : adj[n]) {
    if (!vis[h]) {
      dfs(h, n);
      // printf("Low[%d] = min(%d, %d) = %d\n", n, low[n], low[h], min(low[n], low[h]));
      low[n] = min(low[h], low[n]);
      if ((n == 0 && child[0].size() > 1) || (n != 0 && low[h] >= start[n])) {
	art.insert(n);
      }
    } else if (h != p) {
      low[n] = min(low[n], start[h]);
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v); adj[v].pb(u);
  }
  dfs(0);
  for (int h : art) cout << h << endl;
}

