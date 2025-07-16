#include<bits/stdc++.h>
using namespace std;
#define D isdigit(c=getchar())
inline int getint(){
    int c,l=0,x;
    for (;!D;l=c)if(c==EOF)return 1<<31;
    for (x=c-'0';D;x=x*10+c-'0')if(c==EOF) break;
    return l=='-'?-x:x;
}
int dist[16][16],f[1<<16],dp[16][1<<16],g[1<<16][16],n,m;
int main(){
	n=getint();m=getint();
	for(int i=1;i<=m;i++){
		int x=getint(),y=getint();
		dist[x][y]=dist[y][x]=getint();
	}
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if((i&(1<<j-1))&&(!(i&(1<<k-1))))f[i]+=dist[j][k];
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<(1<<n);i++)
		if(i&1){
			dp[1][i]=f[i];
			for(int j=1;j<=n;j++)if(dist[1][j])g[i][j]=1;
		}
	for(int i=1;i<(1<<n);i++)if(i&1){
		for(int k=2;k<=n;k++)if(i&(1<<k-1)){
			for(int j=i-(1<<k-1);j;j=j-1&i-(1<<k-1))if(j&1){
				int l=g[j][k];if(!l)continue;
				dp[k][i]=min(dp[k][i],dp[l][j]-2*dist[l][k]+f[i-j]);
			}
		//	printf("dp[%d][%d]=%d\n",k,i,dp[k][i]);
		}
		for(int k=1;k<=n;k++){
			int mx=0x3f3f3f3f;g[i][k]=0;
			for(int l=1;l<=n;l++)if(i&(1<<l-1)&&dist[l][k]&&dp[l][i]-2*dist[l][k]<mx){
				mx=dp[l][i]-2*dist[l][k];g[i][k]=l;
			}
		}
	}
	printf("%d\n",dp[n][(1<<n)-1]/2);
	return 0;
}
//MainFunction
