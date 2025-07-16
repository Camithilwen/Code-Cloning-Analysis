#include<bits/stdc++.h>
using namespace std;
#define reg register
#define ll long long
#define maxn 100005
inline ll read()
{
	ll x=0,w=0;char ch=getchar();
	while(!isdigit(ch))w|=ch=='-',ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w?-x:x;
}
int n,m;ll k;
int b[maxn],to[70][maxn],c[maxn];
double a[maxn],d[maxn];
int main()
{
    n=read();reg int i,j;
    for(i=1;i<=n;++i)a[i]=read();
    for(i=2;i<=n;++i)d[i]=a[i]-a[i-1];
    m=read(),k=read();
    for(i=1;i<=m;++i)b[i]=read();
    for(i=1;i<=n;++i)to[0][i]=i,c[i]=i;
    for(i=1;i<=m;++i)swap(to[0][b[i]],to[0][b[i]+1]);
    for(j=1;j<=62;++j)for(i=2;i<=n;++i)
        to[j][i]=to[j-1][to[j-1][i]];
    for(j=62;j>=0;--j)if(k>=(1ll<<j))
    {
        for(i=2;i<=n;++i)c[i]=to[j][c[i]];
        k^=(1ll<<j);
    }
    for(i=2;i<=n;++i)a[i]=d[c[i]]+a[i-1];
    for(i=1;i<=n;++i)printf("%.9lf\n",a[i]);
	return 0;
}
