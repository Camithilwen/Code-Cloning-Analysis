#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;
const int INF = 1 << 24;
int c[200][200];
int t[200][200];
int cost[200][200];
int tim[200][200];

int main(){
  int n, m, K;
  int p, q, r;
  while(cin >> n >> m && (n || m)){
    fill(&cost[0][0], &cost[199][199] + 1, INF);
    fill(&tim[0][0], &tim[199][199] + 1, INF);
    for(int i = 1; i <= m; i++){
      cost[i][i] = tim[i][i] = 0;
      c[i][i] = t[i][i] = 0;
    }

    for(int i = 0; i < n; i++){
      int a, b;
      int d, e;
      cin >> a >> b;
      cin >> d >> e;
      cost[b][a] = min(cost[b][a], d);
      cost[a][b] = min(cost[a][b], d);
      tim[b][a] = min(tim[b][a], e);
      tim[a][b] = min(tim[a][b], e);
    }

    for(int k = 1; k <= m; k++){
      for(int i = 1; i <= m; i++){
	for(int j = 1; j <= m; j++){
	  if(cost[i][j] > cost[i][k] + cost[k][j]){
	    cost[i][j] = cost[i][k] + cost[k][j];
	  }
	  if(tim[i][j] > tim[i][k] + tim[k][j]){
	    tim[i][j] = tim[i][k] + tim[k][j];
	  }
	}
      }
    }
    cin >> K;    
    for(int i = 0; i < K; i++){
      cin >> p >> q >> r;
      if(!r){
	cout << cost[p][q] << endl;
      }else{
	cout << tim[p][q] << endl;
      }
    }
    
  }
  return 0;
}
	
    