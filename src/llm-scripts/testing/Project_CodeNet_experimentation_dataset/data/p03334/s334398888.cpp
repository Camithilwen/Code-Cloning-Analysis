#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=605;

int n,m,dx[MAXN*4],dy[MAXN*4];
void work(int d)
{
	m=0;
	for(int i=-n;i<=n;++i)
		for(int j=-n;j<=n;++j)
			if(i*i+j*j==d)dx[++m]=i,dy[m]=j;
}
int c1[MAXN][MAXN],c2[MAXN][MAXN];
void dfs(int x,int y,int c[MAXN][MAXN])
{
	int tx,ty;
	for(int i=1;i<=m;++i)
	{
		tx=x+dx[i],ty=y+dy[i];
		if(tx<0 || ty<0 || tx>=n || ty>=n || c[tx][ty])continue;
		c[tx][ty]=3-c[x][y];
		dfs(tx,ty,c);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int d;
	readint(n);n*=2;
	readint(d);work(d);
	for(int x=0;x<n;++x)
		for(int y=0;y<n;++y)
		{
			if(c1[x][y])continue;
			c1[x][y]=1;
			dfs(x,y,c1);
		}
	readint(d);work(d);
	for(int x=0;x<n;++x)
		for(int y=0;y<n;++y)
		{
			if(c2[x][y])continue;
			c2[x][y]=1;
			dfs(x,y,c2);
		}
	for(int i=1;i<=2;++i)
		for(int j=1;j<=2;++j)
		{
			int ans=0;
			for(int x=0;x<n;++x)
				for(int y=0;y<n;++y)
					if(c1[x][y]==i && c2[x][y]==j)++ans;
			if(ans*4>=n*n)
			{
				ans=n*n/4;
				for(int x=0;x<n;++x)
					for(int y=0;y<n;++y)
						if(c1[x][y]==i && c2[x][y]==j)
						{
							printf("%d %d\n",x,y);
							--ans;
							if(!ans)return 0;
						}
			}
		}
	return 0;
}