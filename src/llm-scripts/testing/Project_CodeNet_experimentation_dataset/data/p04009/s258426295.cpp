#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
using namespace std;
const int N=105;
char mp[N][N];
int n,m,ex,ey,ans,dp[N][N][N];
int sr[N][N],sc[N][N];
void mx(int &x,int y){x<y?x=y:0;}
int main(){
	scanf("%d%d",&n,&m);
	memset(dp,233,sizeof(dp));
	For(i,1,n) scanf("%s",mp[i]+1);
	For(i,1,n) For(j,1,m){
		if (mp[i][j]=='o') sr[i][j]=sc[i][j]=1;
		else if (mp[i][j]=='E') ex=i,ey=j;
		sr[i][j]+=sr[i][j-1],sc[i][j]+=sc[i-1][j];
	}
	int L=ey-1,R=m-ey,U=ex-1,D=n-ex; dp[0][0][0]=0;
	For(l,0,L) For(r,0,R) For(u,0,U) For(d,0,D){
		int v=dp[r][u][d]; ans=max(ans,v);
		int up=max(ex-u,d+1),dn=min(ex+d,n-u),le=max(ey-l,r+1),ri=min(ey+r,m-l);
		if (up>dn||le>ri) continue;
		if (u<U-d) mx(dp[r][u+1][d],v+sr[ex-u-1][ri]-sr[ex-u-1][le-1]);
		if (d<D-u) mx(dp[r][u][d+1],v+sr[ex+d+1][ri]-sr[ex+d+1][le-1]);
		if (r<R-l) mx(dp[r+1][u][d],v+sc[dn][ey+r+1]-sc[up-1][ey+r+1]);
		if (l<L-r) mx(dp[r][u][d],v+sc[dn][ey-l-1]-sc[up-1][ey-l-1]);
	}
	printf("%d",ans);
}