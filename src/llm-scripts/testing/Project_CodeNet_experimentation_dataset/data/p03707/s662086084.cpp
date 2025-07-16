// This code wrote by chtholly_micromaker(MicroMaker)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define reg register
using namespace std;
const int MaxN=2050;
const int dir[4][2]={1,0,0,1,-1,0,0,-1};
template <class t> inline void read(t &s)
{
	s=0;
	reg int f=1;
	reg char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
		s=(s<<3)+(s<<1)+(c^48),c=getchar();
	s*=f;
	return;
}
char G[MaxN][MaxN];
int f[MaxN][MaxN],g[MaxN][MaxN],h[MaxN][MaxN];
int n,m;
signed main(void)
{
	// freopen("big.in","r",stdin);
	int q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;++i)
		scanf("%s",G[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+(G[i][j]=='1'?1:0);
			g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
			h[i][j]=h[i-1][j]+h[i][j-1]-h[i-1][j-1];
			if(G[i][j]=='1')
			{
				if(G[i-1][j]=='1')
					++g[i][j];
				if(G[i][j-1]=='1')
					++h[i][j];
			}
		}
	reg int U,V,X,Y;
	for(int qq=0;qq<q;++qq)
	{
		read(U);read(V);read(X);read(Y);
		reg int ans=f[X][Y]-f[U-1][Y]-f[X][V-1]+f[U-1][V-1];
		// printf("t1 %d\n",f[X][Y]-f[U-1][Y]-f[X][V-1]+f[U-1][V-1]);
		ans-=g[X][Y]-g[U][Y]-g[X][V-1]+g[U][V-1];
		// printf("t2 %d\n",g[X][Y]-g[U][Y]-g[X][V-1]+g[U][V-1]);
		ans-=h[X][Y]-h[U-1][Y]-h[X][V]+h[U-1][V];
		// printf("t3 %d\n",h[X][Y]-h[U-1][Y]-h[X][V]+h[U-1][V]);
		printf("%d\n",ans);
	}
	return 0;
}

