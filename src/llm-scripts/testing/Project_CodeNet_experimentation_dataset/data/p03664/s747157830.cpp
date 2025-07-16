#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)
#define lb(x) (x&-x)
#define get(x) ((int)log2(x))

const int INF=0x3f3f3f3f;
const int N=66666;

int f[17][N],sum[N];
int v[17][17];

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):v,ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

void upd(int &x,int v) {
	(x<v)?(x=v):0;
}

int main(void) {
	int n=read(),m=read();
	int prt=0;
	rep(i,1,m) {
		int x=read()-1,y=read()-1;
		v[x][y]=v[y][x]=read(),prt+=v[x][y];
	}
	for (int S=1;S<(1<<n);++S) {
		int x=get(lb(S));
		sum[S]=sum[S-(1<<x)];
		rep(i,0,n-1) if (v[i][x]&&(S>>i&1)) {
			sum[S]+=v[i][x];
		}
	}
	rep(i,0,n-1) for (int S=0;S<(1<<n);++S) f[i][S]=-INF;
	int ans=0; f[0][1]=0;
	for (int S=1;S<(1<<n);++S) {
		if (!(S&1)) continue;
		rep(i,0,n-1) {
			if (!((S>>i))&1) continue;
			for (int T=S;T;T=(T-1)&S) {
				if (T>>i&1) upd(f[i][S],f[i][S-T+(1<<i)]+sum[T]);
			}
			for (int T=(1<<n)-1-S,j;T;T-=lb(T)) {
				j=get(lb(T));
				if (v[i][j]) upd(f[j][S+(1<<j)],f[i][S]+v[i][j]);
			}
		}
		if (S>>(n-1)&1) upd(ans,f[n-1][S]);
	}
	printf("%d\n", prt-ans);
	return 0;
}