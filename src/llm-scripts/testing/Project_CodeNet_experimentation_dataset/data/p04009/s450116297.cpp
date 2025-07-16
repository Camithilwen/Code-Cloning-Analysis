#include<bits/stdc++.h>
#define N 105
using namespace std;
char s[N][N];
int n,m;
int Ex,Ey,ans;
int cnt[N][N];
void mmax(int &x,int v){
	x=max(x,v);ans=max(ans,v);
}
int get(int x1,int y1,int x2,int y2){
	return cnt[x2][y2]-cnt[x2][y1-1]-cnt[x1-1][y2]+cnt[x1-1][y1-1];
}
int dp[2][N][N][N];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			cnt[i][j]=cnt[i-1][j]+cnt[i][j-1]-cnt[i-1][j-1]+(s[i][j]=='o');
			if(s[i][j]=='E') Ex=i,Ey=j;
		}
	int now=0;
	for (int i=0;i<=Ex-1;i++){
		memset(dp[now^1],0,sizeof(dp[0]));
		for (int j=0;j<=n-Ex;j++)
			for (int k=0;k<=Ey-1;k++)
				for (int L=0;L<=m-Ey;L++){
					int v=dp[now][j][k][L];
					int xl=max(Ex-i,j+1),yl=max(Ey-k,L+1),xr=min(Ex+j,n-i),yr=min(Ey+L,m-k);
					if (Ex-i-1>j) mmax(dp[now^1][j][k][L],v+get(Ex-i-1,yl,Ex-i-1,yr));
					if (Ex+j<n-i) mmax(dp[now][j+1][k][L],v+get(Ex+j+1,yl,Ex+j+1,yr));
					if (Ey-k-1>L) mmax(dp[now][j][k+1][L],v+get(xl,Ey-k-1,xr,Ey-k-1));
					if (Ey+L<m-k) mmax(dp[now][j][k][L+1],v+get(xl,Ey+L+1,xr,Ey+L+1));
				}
		now^=1;
	}
	printf("%d\n",ans);
	return 0;
}