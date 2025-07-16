#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 1 << 30
#define EPS 1e-10
#define MAX_N 100

typedef pair<int, int> P;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

struct edge{ int to, cost; };

vector<vector<edge> >G(MAX_N);
int n;
int d[MAX_N];

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P> >q;
  fill(d, d + n, INF);
  d[s] = 0;
  q.push(P(0, s));

  while(!q.empty()){
    P p = q.top(); q.pop();
    int v = p.S;
    if(d[v] < p.F) continue;
    rep(i, G[v].size()){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
	d[e.to] = d[v] + e.cost;
	q.push(P(d[e.to], e.to));
      }
    }
  }
}

int main(){
  int k;
  while(scanf("%d%d", &n, &k) && n+k){
    rep(i, MAX_N) G[i].clear();
    int a, b, c;
    rep(i, k){
      scanf("%d", &a);
      if(a){
	scanf("%d%d%d", &a, &b, &c); b--; a--;
	edge e;
	e.to = b; e.cost = c;
	G[a].PB(e);
	e.to = a;
	G[b].PB(e);
      }else{
	scanf("%d%d", &a, &b); a--; b--;
	dijkstra(a);
	printf("%d\n", d[b]==INF?-1:d[b]);
      }
    }
  }
  return 0;
}