#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define INF (1<<29)

int G[101][101];
int n, k;

void init(){
  for(int i = 0 ; i < n ; i++){
    for(int j = 0 ; j < n ; j++){
      G[i][j] = INF;
      if(i == j) G[i][j] = 0;
    }
  }
}

int main(){
  while(cin >> n >> k){
    if(n == 0 && k == 0) break;
    init();

    int op, a, b, e;
    for(int cs = 0 ; cs < k ; cs++){
      cin >> op;
      if(op == 1){
	cin >> a >> b >> e;
	a--, b--;
	G[a][b] = min(G[a][b], e);
	G[b][a] = min(G[b][a], e);
	//	Warshall_Floyd();
	  for(int i = 0 ; i < n ; i++){
	    for(int j = 0 ; j < n ; j++){
	      G[i][j] = min(G[i][j], G[i][a] + G[a][b] + G[b][j]);
	      G[j][i] = G[i][j];
	    }
	  }
      }
      else if(op == 0){
	cin >> a >> b;
	a--, b--;
	if(G[a][b] == INF) cout << -1 << endl;
	else cout << G[a][b] << endl;
      }
    }
  }
  return 0;
}