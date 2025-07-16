#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using VI = vector<int>;

const int N = 1e5 + 10;
VI adj[N];
int col[N];
bool bip = true;
int f[3];

void dfs(int u, int c) {
  if (col[u] != 0) {
    if (c != col[u]) bip = false;
    return;
  }
  col[u] = c;
  f[c]++;

  for (int v: adj[u]) {
    dfs(v, 3 - c);
  }
}

int main() {
#ifdef LOCAL_EXEC
//	freopen("sample.in", "r", stdin);
//	freopen("sample.out", "w", stdout);
#else
  ios_base::sync_with_stdio(false); cin.tie(NULL);
#endif

  int n; cin >> n;
  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1, 1);
  ll ans = 0;
  if (!bip) {
    ans = (n * 1ll * (n - 1)) / 2 - m;
  } else {
    ans = f[1] * 1ll * f[2] - m;
  }

  cout << ans << endl;

  return 0;
}
