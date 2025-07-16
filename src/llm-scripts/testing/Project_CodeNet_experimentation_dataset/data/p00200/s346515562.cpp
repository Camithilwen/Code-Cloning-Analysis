#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#define N 101
#define INF 200000000
using namespace std;

int main(void){
	int a,b,c,d;
	int n,m;
	while(cin>>n>>m,n||m){
		int dp[m+1][m+1];
		int dp1[m+1][m+1];
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j)dp[i][j]=dp1[i][j]=0;
				else dp[i][j]=dp1[i][j]=INF;
			}
		}

		for(int i=0;i<n;i++){
			cin>>a>>b>>c>>d;
			dp[b][a]=c;
			dp[a][b]=c;
			dp1[b][a]=d;
			dp1[a][b]=d;
		}

		for(int k=1;k<=m;k++){
			for(int u=1;u<=m;u++){
				for(int v=1;v<=m;v++){
					dp[u][v]=min(dp[u][v],dp[u][k]+dp[k][v]);
					dp1[u][v]=min(dp1[u][v],dp1[u][k]+dp1[k][v]);
				}
			}
		}

		int k;
		cin>>k;
		while(k--){
			cin>>a>>b>>c;
			if(c) cout<<dp1[a][b]<<endl;
			else cout<<dp[a][b]<<endl;
		}
	}
	return 0;
}