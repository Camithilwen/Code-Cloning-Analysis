#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
s64 C2(int n)
{
	return (s64)n*(n-1)/2;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1e5+5;
int fa[N],sz[N];bool d[N],have[N];
int find(int x)
{
	if(fa[x]==x)return x;
	find(fa[x]);
	d[x]^=d[fa[x]];
	return fa[x]=fa[fa[x]];
}

int main()
{
	//freopen("1.in","r",stdin);
	int n,m;
	cin>>n>>m;
	rep(i,1,n){fa[i]=i;sz[i]=1;}
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int fx=find(x),fy=find(y);
		if(fx==fy)
		{
			have[fx]|=d[x]==d[y];
			continue;
		}
		fa[fy]=fx;d[fy]=d[x]^1^d[y];
		sz[fx]+=sz[fy];
		have[fx]|=have[fy];
	}
	int cnt1=0,cnt[2]={};
	rep(x,1,n)
	if(fa[x]==x)
	if(sz[x]==1)++cnt1;
	else ++cnt[have[x]];
	cout<<(s64)cnt[1]*cnt[0]*2+(s64)cnt1*(n-cnt1)*2
		+(s64)cnt[1]*cnt[1]+(s64)cnt[0]*cnt[0]*2+(s64)cnt1*cnt1;
}