#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
#define all(x) x.begin(), x.end()
#define rep(i,a,b) for(int i = a; i < b; i++)

int V, E;
vvi conn(100002);
vi vis(100002);
vb trail(100002);
vb cut(100002);

int dfs_min(int v, int depth, int parent) {
  if(vis[v] > 0) return vis[v];
  vis[v] = depth;
  trail[v] = true;

  int minHit = depth;
  rep(i,0,(int)conn[v].size()) {
    if(conn[v][i] != parent && (vis[conn[v][i]] == 0 || trail[conn[v][i]])) {
      int hit = dfs_min(conn[v][i], depth+1, v);
      minHit = min(minHit, hit);
      if(hit >= depth && conn[v].size() > 1)
	cut[v] = true;
    }
  }

  trail[v] = false;
  return minHit;
}

int main() {
  cin >> V;
  cin >> E;
  rep(e,0,E) {
    int s, t;
    cin >> s;
    cin >> t;
    conn[s].push_back(t);
    conn[t].push_back(s);
  }

  dfs_min(0, 1, -1);
  if(V > 1) {
    cut[0] = false;
    bool remember = cut[1];
    fill(all(vis), 0);
    dfs_min(1, 1, -1);
    cut[1] = remember;
  }

  rep(v,0,V)
    if(cut[v])
      cout << v << '\n';
}

