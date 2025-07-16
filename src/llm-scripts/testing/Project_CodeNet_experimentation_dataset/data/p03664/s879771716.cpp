#include<bits/stdc++.h>
using namespace std;
const int md=1e9+7;
int n,m,f[33005][20],c[33005][20],d[20][20];
vector<pair<int,int> >g[20];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);u--;v--;
		d[u][v]=d[v][u]=w;
	}
	for(int msk=0;msk<(1<<n);msk++)for(int i=0;i<n;i++)
	{
		f[msk][i]=1e9+7;
		for(int j=0;j<n;j++)if(msk&(1<<j))c[msk][i]+=d[i][j];
	}
	f[1][0]=0;
	for(int msk=0;msk<(1<<n);msk++)
	{
		for(int i=0;i<n;i++)if(msk&(1<<i)&&f[msk][i]!=1e9+7)
		{
			for(int j=0;j<n;j++)
			{
				if(!(msk&(1<<j))&&d[i][j])
				{
					f[msk|(1<<j)][j]=min(f[msk|(1<<j)][j],f[msk][i]+c[msk][j]-d[i][j]);
				}
			}
			int nxt=msk^(1<<i),st=((1<<n)-1)^msk,s;
			for(int j=st;j>0;j=(j-1)&st)
			{
				s=0;
				for(int l=0;l<n;l++)if(j&(1<<l))s+=c[nxt][l];
				f[msk|j][i]=min(f[msk|j][i],f[msk][i]+s);
			}
		}
	}
	printf("%d\n",f[(1<<n)-1][n-1]);
	return 0;
}