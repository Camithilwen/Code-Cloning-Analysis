#include <bits/stdc++.h>
using namespace std;

#define INF 1e+9
#define MAX_V 2505

struct edge {
  int to;
  int cost;
};

using P = pair<int, int>;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  fill(d, d+V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while ( !que.empty() ) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) { continue; }

    for ( int i = 0; i < G[v].size(); i++ ) {
      edge e = G[v][i];
      if ( d[e.to] > d[v] + e.cost ) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int h, w;
int pos(int i, int j) { return i*w + j; }

int main() {
  cin >> h >> w;
  V = h * w;
  string table[h];
  for ( int i = 0; i < h; i++ ) { cin >> table[i]; }

  int black = 0;
  for ( int i = 0; i < h; i++ ) {
    for ( int j = 0; j < w; j++ ) {
      if ( table[i][j] == '#' ) { black++; continue; }
      if ( i+1 < h )  { G[pos(i,j)].push_back({pos(i+1,j), 1}); }
      if ( i-1 >= 0 ) { G[pos(i,j)].push_back({pos(i-1,j), 1}); }
      if ( j+1 < w )  { G[pos(i,j)].push_back({pos(i,j+1), 1}); }
      if ( j-1 >= 0 ) { G[pos(i,j)].push_back({pos(i,j-1), 1}); }
    }
  }

  dijkstra(pos(0,0));
  int ans = -1;
  if ( d[pos(h-1,w-1)] != INF ) {
    ans = h*w - d[pos(h-1,w-1)] - black - 1;
  }

  cout << ans << endl;
  return 0;
}
