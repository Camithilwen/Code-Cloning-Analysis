#include <cstdio>
#include <iostream>
#include <string>
#define INF (1<<21)
using namespace std;

int main(){
  int i,j,n,k,c,a,b,G[101][101],d[101],f[101],yen,p,min,s,g;
  while(1){
    cin >> n >> k;
    if(n == 0 && k == 0) break;

    for(i=0;i<=n;i++){
      for(j=0;j<=n;j++){
	G[i][j] = INF;
      }
    }

    for(i=0;i<k;i++){
      cin >> c;
      if(c == 1){
	cin >> a >> b >> yen;
	if(G[a][b] > yen) G[a][b] = G[b][a] = yen;
      }

      else if(c == 0){
	for(j=0;j<=n;j++){
	  d[j] = INF;
	  f[j] = 0;
	}
	cin >> s >> g;

	d[s] = 0;
	while(1){
	  min = INF;
	  for(j=0;j<=n;j++){
	    if(d[j]<min && f[j] == 0){
	      min = d[j];
	      p = j;
	    }
	  }
	  if(min == INF) break;
	  f[p] = 1;
	  for(j=0;j<=n;j++){
	    if(f[j] == 1) continue;
	    if(G[p][j] + d[p] < d[j]) d[j] = G[p][j] + d[p];
	  }
	}

	if(d[g] == INF) cout << "-1" << endl;
	else cout << d[g] << endl;
      }
    }
  }
  return 0;
}