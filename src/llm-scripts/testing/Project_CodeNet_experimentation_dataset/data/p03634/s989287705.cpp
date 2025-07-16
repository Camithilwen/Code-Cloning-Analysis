#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

struct edge {
  ll to, cost;
};

vector<vector<edge>> g;
vector<bool> visited;
vector<ll> dist;

void dfs(int s) {
  visited[s] = true;
  rep(i, g[s].size()) {
    if (visited[g[s][i].to]) continue;
    int to = g[s][i].to, cost = g[s][i].cost;
    dist[to] = dist[s] + cost;
    dfs(to);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  ll n;
  cin >> n;
  g.resize(n);
  visited.resize(n);
  dist.resize(n);
  rep(i, n) {
    visited[i] = false;
    dist[i] = LINF;
  }
  rep(i, n - 1) {
    ll a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    g[a].push_back(edge{b, c});
    g[b].push_back(edge{a, c});
  }
  ll q, k;
  cin >> q >> k;
  --k;
  dist[k] = 0;
  dfs(k);
  rep(i, q) {
    ll x, y, ans = 0;
    cin >> x >> y;
    --x;
    --y;
    cout << dist[x] + dist[y] << endl;
  }
  return 0;
}
