#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(var) cerr << (#var) << " = " << (var) << endl;
#else
#define debug(var)
#endif

void init() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}

const int N = 1e5+23;

vector<int> g[N], ans;
bool bio[N];
int parent[N];

void dfs(int u) {
  bio[u] = true;
  for (int v: g[u]) {
    if (bio[v]) continue;
    dfs(v);
  }
  ans.push_back(u);
}

void solve() {
  int n, m; scanf("%d%d", &n, &m);
  for (int u, v, i = 0; i < n-1+m; ++i) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
  }
  for (int i = 1; i <= n; ++i) {
    if (bio[i]) continue;
    dfs(i);
  }
  for (int u: ans)
    for (int v: g[u])
      if (!parent[v])
	parent[v] = u;
  for (int i = 1; i <= n; ++i) printf("%d\n", parent[i]);
}

int main() {
  init();
  int t = 1; //scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
