#include<bits/stdc++.h>
#define ll long long
#define N 20
#define inf 1e9
#define rep(i,j,k) for(ll i=j;i<=k;++i)
using namespace std;
inline ll read(){
    ll x=0,f=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
    return f?-x:x;
}
ll n,m,G[N][N],f[1<<N][N],s[1<<N],sum;
int main(){
    n=read();m=read();
    rep(i,1,m){
		ll x=read()-1,y=read()-1;
		G[x][y]=G[y][x]=read(); sum+=G[x][y];
	}
    rep(i,0,1<<n) rep(j,0,n) if((i>>j)&1)
		rep(k,j+1,n) if((i>>k)&1) s[i]+=G[j][k];
    rep(i,0,1<<n) rep(j,0,n) f[i][j]=-inf;
    rep(i,0,1<<n) if(i&1) f[i][0]=s[i];
    rep(i,0,1<<n) rep(j,0,n) if((i>>j)&1)
		for(ll k=i;k;k=(k-1)&i) if(k&1)
			rep(l,0,n) if(((k>>l)&1)&&((~k>>j)&1)&&G[l][j])
				f[i][j]=max(f[i][j],f[k][l]+G[l][j]+s[i^k]);
    printf("%d\n",sum-f[(1<<n)-1][n-1]);
    return 0;
}