#include<bits/stdc++.h>
using namespace std;
const int maxn=100010,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,lim,wsum,e[15][15],f[1<<15][15],tot[1<<15];
inline void chkmax(int &x,int y){if(x<y) x=y;}
int main(){
	n=read();m=read();lim=1<<n;
	FOR(i,1,m){
		int u=read()-1,v=read()-1;
		wsum+=e[u][v]=e[v][u]=read();
	}
	FOR(i,0,lim-1) FOR(j,0,n-1) if((i>>j)&1) FOR(k,j+1,n-1) if((i>>k)&1) tot[i]+=e[j][k];
	MEM(f,~0x3f);
	f[1][0]=0;
	FOR(i,1,lim-1) FOR(j,0,n-1) if((i>>j)&1){
		FOR(k,0,n-1) if(!((i>>k)&1) && e[j][k]) chkmax(f[i|(1<<k)][k],f[i][j]+e[j][k]);
		int re=(lim-1)^i;
		for(int k=re;k;k=((k-1)&re)) chkmax(f[i|k][j],f[i][j]+tot[k|(1<<j)]);
	}
	printf("%d\n",wsum-f[lim-1][n-1]);
}