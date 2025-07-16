#include<iostream>
#define INF 2 << 23
using namespace std;
int main(){
  int n,m;
  while(cin >> n >> m){
    if(n==0&&m==0) break;
    int cost[m+1][m+1];
    int time[m+1][m+1];

    for(int i=0;i<=m;i++)
      for(int j=0;j<=m;j++){
        if(i==j)
          cost[i][j] = time[i][j] = 0;
        else
          cost[i][j] = time[i][j] = INF;
      }

    for(int i=0;i<n;i++){
      int a,b;
      cin >> a >> b;
      cin >> cost[a][b] >> time[a][b];
      cost[b][a] = cost[a][b]; time[b][a] = time[a][b];
    }

    for (int i = 1; i <= m; i++)      // ?????±????????????
      for (int j = 1; j <= m; j++)    // ????§???????
        for (int k = 1; k <= m; k++){  // ??????
          cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
          time[j][k] = min(time[j][k], time[j][i] + time[i][k]);
        }

    int k;
    cin >> k;
    int p,q,r;
    for(int i=0;i<k;i++){
      cin >> p >> q >> r;
      switch(r){
      case 0: cout << cost[p][q] << endl; break;
      case 1: cout << time[p][q] << endl; break;
      default: break;
      }
    }
  }
}