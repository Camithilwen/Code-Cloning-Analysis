#include<bits/stdc++.h>
using namespace std;

#define Abigail inline void
typedef long long LL;

const int N=15,INF=(1<<30)-1;

int n,m,e[N+9][N+9],sum;
int a[(1<<N)+9];

void Get_a(){
  for (int g=1;g<1<<n;++g)
    for (int i=0;i<n;++i){
    	if (g>>i&1^1) continue;
    	for (int j=i+1;j<n;++j)
    	  if (g>>j&1) a[g]+=e[i][j];
		}
} 

int b[N+9][(1<<N)+9];

void Get_b(){
  for (int g=1;g<1<<n;++g)
  	for (int i=0;i<n;++i){
  		if (g>>i&1) continue;
  	  b[i][g]=a[g];
  		for (int j=0;j<n;++j)
  		  if (g>>j&1) b[i][g]+=e[i][j];
		}
}

int dp[N+9][(1<<N)+9];

void Get_dp(){
  for (int i=0;i<n;++i)
    for (int g=0;g<1<<n;++g) dp[i][g]=-INF;
  dp[0][1]=0;
  for (int g1=1;g1<1<<n;++g1)
  	for (int i=0;i<n;++i){
  		if (dp[i][g1]==-INF) continue;
  		int t=~g1&(1<<n)-1;
  		for (int g2=t;g2;g2=g2-1&t)
  			dp[i][g1|g2]=max(dp[i][g1|g2],dp[i][g1]+b[i][g2]);
  		for (int j=0;j<n;++j)
  		  if (g1>>j&1^1&&e[i][j]){
				  dp[j][g1|1<<j]=max(dp[j][g1|1<<j],dp[i][g1]+e[i][j]);
				}
		}
}

Abigail into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=m;++i){
  	int x,y,v;
  	scanf("%d%d%d",&x,&y,&v);--x;--y;
  	e[x][y]=e[y][x]=v;
  	sum+=v;
	}
}

Abigail work(){
  Get_a();
  Get_b();
  Get_dp();
}

Abigail outo(){
  printf("%d\n",sum-dp[n-1][(1<<n)-1]);
}

int main(){
  into();
  work();
  outo();
  return 0;
}