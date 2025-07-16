#include<iostream>
#include<queue>
using namespace std;
#define MAX 500
#define rep(i, n) for ( int i = 0; i < n; i++)

bool G[MAX][MAX];
int n, m;

int bfs(){
  queue<int> q;
  int d[MAX];
  rep(i, n) d[i] = (1<<21);

  q.push(0);
  d[0] = 0;

  int u;
  while(!q.empty()){
    u = q.front(); q.pop();

    rep(v, n){
      if ( d[v] == (1<<21) && G[u][v] ){
	d[v] = d[u] + 1;
	q.push(v);
      }
    }
  }

  int cnt = 0;
  rep(i, n) if ( d[i] == 1 || d[i] == 2 ) cnt++;
  return cnt;
}

main(){
  int s, t;
  while(1){
    cin >> n >> m;
    if ( n == 0 && m == 0 ) break;
    rep(i, n) rep(j, n) G[i][j] = false;

    rep(i, m){
      cin >> s >> t;
      s--; t--;
      G[s][t] = G[t][s] = true;
    }
    
    cout << bfs() << endl;
  }
}