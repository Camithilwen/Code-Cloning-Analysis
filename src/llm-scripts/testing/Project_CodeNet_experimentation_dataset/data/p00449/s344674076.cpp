#include <iostream>

#define MX 1000000000

using namespace std;
int M[100][100],N; //M[i][j]:i©çjÜÅÌRXg

int dijkstra(int s , int g){
  bool visited[100];
  int d[100];
  for(int i=0;i < N;i++) d[i] = MX , visited[i] = false;
  d[s] = 0;
  while(1){
    int u;
    int mincost = MX;
    for(int i=0;i<N;i++)if(!visited[i] && d[i] < mincost) mincost = d[i] , u = i;
    if(mincost == MX) break;
    visited[u] = true;
    for(int v=0;v<N;v++){
      if(visited[v] || M[u][v] == MX) continue;
      if(d[v] > d[u] + M[u][v]) d[v] = d[u] + M[u][v];
    }
  }
  return d[g];
}
    
int main(){
  int k;
  while(cin >> N >> k){
    for(int i=0;i<N;i++)for(int j=0;j<N;j++) M[i][j] = MX;
    while(k--){
      int x,a,b,c;
      cin >> x;
      if(!(x)){
        int cost;
        cin >> a >> b;
        cost = dijkstra(a-1,b-1);
        if(cost == MX) cout << "-1" << endl;
        else cout << cost << endl;
      }
      else {
        cin >> a >> b >> c;        
        if(M[a-1][b-1] > c && M[b-1][a-1] > c) M[a-1][b-1] = M[b-1][a-1] = c;
      }
    }
  }
  return 0;
}