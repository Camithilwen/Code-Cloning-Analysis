#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int inf=0x3f3f3f3f;
int val[15][15],sum[1<<15],dp[15][1<<15],f[15];
int main(){
	int n=read(),m=read();
	while(m--){
		int x=read()-1,y=read()-1,z=read();
		val[x][y]=z,val[y][x]=z;
		sum[(1<<x)|(1<<y)]=z;
	}
	REP(i,0,n-1) REP(j,0,(1<<n)-1) if((1<<i)&j) sum[j]+=sum[j^(1<<i)];
	REP(i,0,n-1) REP(j,0,(1<<n)-1) dp[i][j]=-inf;
	REP(j,1,(1<<n)-1) if(j&1) dp[0][j]=sum[j];
	REP(i,1,(1<<n)-1){
		REP(j,0,n-1) f[j]=-inf;
		REP(j,0,n-1) if(i&(1<<j)) REP(k,0,n-1) if(val[j][k] && (i&(1<<k))==0) chkmax(f[k],dp[j][i]+val[j][k]);
		REP(j,0,n-1) if((i&(1<<j))==0)
			for(int cur=i|(1<<j),k=cur;k<=iend;k=(k+1)|cur)
				chkmax(dp[j][k],f[j]+sum[k^i]);
	}
	printf("%d\n",sum[(1<<n)-1]-dp[n-1][(1<<n)-1]);
	return 0;
}
