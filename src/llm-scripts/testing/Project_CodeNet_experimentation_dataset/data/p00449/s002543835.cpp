#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 100000000;

int cost[101][101];
int d[101];
bool used[101];
int n,k;

int dijkstra(int s, int g) {
  fill(d,d+n,INF);
  fill(used,used+n,false);
  d[s] = 0;

  while(true) {
    int v = -1;
    
    for (int u = 0; u < n; u++ ) {
      if (!used[u] && ( v == -1 || d[u] < d[v])) v = u;
    }

    if (v == -1) break;
    used[v] = true;

    for (int u = 0; u < n; u++ ) {
      d[u] = min(d[u],d[v] + cost[v][u]);
    }
  }
  if ( d[g] == INF ) return INF;
  else return d[g];

}

int main() {
  while (cin >> n >> k, n||k) {
    for ( int i = 0; i < n; i++ ) {
      for ( int j = 0; j < n; j++ ) {
	cost[i][j] = INF;
      }
    }
    for ( int i = 0; i < k; i++ ) {
      int order; cin >> order;
      if ( order == 0 ) {
	int a,b; cin >> a >> b;
	a--; b--;
	int ans = dijkstra(a,b);
	if ( ans == INF ) cout << -1 << endl;
	else cout << ans << endl;
      } else if ( order == 1 ) {
	int c,d,e; cin >> c >> d >> e;
	c--; d--;
	cost[c][d] = min(e,cost[c][d]);
	cost[d][c] = min(e,cost[d][c]);
      }
    
    }
  }
  return 0;
}