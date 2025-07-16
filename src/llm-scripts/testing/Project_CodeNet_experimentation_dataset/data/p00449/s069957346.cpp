#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 111111111
using namespace std;

long int cost[1000][1000],ans[1000];
int memo[1000];
int n,k,m,a,b,c;

void solve(int s){
  ans[a] = 0;

  while(true){
    int k = -1;

    for(int i=1;i<=n;i++){
      if(!memo[i] && (k == -1 || ans[i] < ans[k])) k = i;
    }

    if(k == -1) break;

    memo[k] = 1;

    for(int i=1;i<=n;i++) ans[i] = min(ans[i],ans[k]+cost[i][k]);
  }
}

int main(){

  while(true){
    cin >> n >> k;
    if(!n && !k) break;

    for(int i=0;i<1000;i++){
      for(int j=0;j<1000;j++) cost[i][j] = INF;
    }

    for(int i=0;i<k;i++){
      cin >> m;

      if(m){
	cin >> a >> b >> c;
	if(cost[a][b] > c) cost[a][b] = cost[b][a] = c;
      }

      if(!m){
	cin >> a >> b;

	for(int i=0;i<1000;i++) ans[i] = INF;
	memset(memo,0,sizeof(memo));
	solve(a);

	if(ans[b] < INF) cout << ans[b] << endl;
	if(ans[b] == INF) cout << -1 << endl;
      }
    }
  }
}