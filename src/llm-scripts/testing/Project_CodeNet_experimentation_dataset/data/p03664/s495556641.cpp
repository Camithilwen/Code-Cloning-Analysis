#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;

const int inf=1e9+10;
const int maxn=16;

int dp[1<<maxn][maxn],dp2[1<<maxn],n,m,cost[maxn][maxn]; 
vector <int> g[1<<maxn]; 

int main(){
	for(int i=0;i<maxn;i++) for(int j=0;j<maxn;j++) 
		cost[i][j]=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		u--; v--;
		cost[u][v]=c;
		cost[v][u]=c;
	}
	for(int mask=0;mask<(1<<n);mask++) 
		for(int i=0;i<n;i++) for(int j=0;j<n;j++)
			if((mask&(1<<i))&&(mask&(1<<j)))
				dp2[mask]=dp2[mask]+cost[i][j];
	for(int mask=0;mask<(1<<n);mask++) dp2[mask]=dp2[mask]/2;
	for(int mask=0;mask<(1<<n);mask++) for(int i=0;i<n;i++) dp[mask][i]=-inf;
	for(int mask=0;mask<(1<<n);mask++) if(mask&1) dp[mask][0]=dp2[mask];
	for(int mask=0;mask<(1<<n);mask++)
		for(int i=0;i<n;i++){
			if((dp[mask][i]==-inf)||!(mask&(1<<i))) continue;
			for(int mask2=(1<<n)-1-mask;mask2>0;mask2=(mask2-1)&((1<<n)-1-mask)){
				for(int j=0;j<n;j++){
					if(mask2&(1<<j)&&cost[i][j]>0){
						dp[mask|mask2][j]=max(dp[mask|mask2][j],dp[mask][i]+cost[i][j]+dp2[mask2]);
					}
				}
			}
		}
	printf("%d\n",dp2[(1<<n)-1]-dp[(1<<n)-1][n-1]);
	return 0;
}