#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = int_fast64_t;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

int n, u, v;
vector<vector<int> > G;
vector<int> depth, maxdepth, parent;
int dfs(int s, int p, int d) {
  depth[s] = d;
  parent[s] = p;
  int maxd = d;
  for(const int t : G[s]) if(t != p) {
    chmax(maxd, dfs(t, s, d+1));
  }
  return maxdepth[s] = maxd;
}
void answer() {
  cin >> n >> u >> v;
  u--; v--;
  G.resize(n);
  depth.resize(n);
  maxdepth.resize(n);
  parent.resize(n);
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  dfs(v, -1, 0);
  int ans = 0;
  int cur = u;
  while(cur != 0) {
    if(depth[u] - depth[cur] < depth[cur]) {
      chmax(ans, maxdepth[cur] - 1);
    } else {
      chmax(ans, maxdepth[u] - 1);
    }
    cur = parent[cur];
  }
  cout << ans << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}