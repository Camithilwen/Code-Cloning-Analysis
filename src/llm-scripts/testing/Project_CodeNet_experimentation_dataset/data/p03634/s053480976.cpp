// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

typedef pair<int, int> Edge;

int n;
vector<Edge> G[100000];
vector<ll> D(100000, 0);

int main() {
  cin >> n;
  loop(i,0,n-1) {
    int a, b, c; cin >> a >> b >> c;
    a--;b--;
    G[a].emplace_back(b, c);
    G[b].emplace_back(a, c);
  }
  int q, k; cin >> q >> k; k--;
  queue<pair<int, int> > Q;
  Q.push({ k, -1 });
  D[k] = 0;
  while (Q.size()) {
    auto _v = Q.front(); Q.pop();
    int v = _v.first, p = _v.second;
    for (auto &&edge: G[v]) {
      int u = edge.first, w = edge.second;
      if (u == p) continue;
      D[u] = D[v] + w;
      Q.push({ u, v });
    }
  }
  
  while (q--) {
    int x, y; cin >> x >> y; x--;y--;
    cout << D[x] + D[y] << endl;
  }
  
  return 0;
}
