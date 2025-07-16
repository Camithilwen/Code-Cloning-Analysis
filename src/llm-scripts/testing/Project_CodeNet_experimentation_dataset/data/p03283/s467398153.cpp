#include<bits/stdc++.h>

using namespace std;

const int N=502;

int n,m,q;
int f[N][N];

int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=m;++i)
	{
		int u,v;
		cin>>u>>v;
		for(int j=v;j<=n;++j)
		{
			f[u][j]++;
		}
	}
	for(int i=1;i<=q;++i)
	{
		int u,v;
		cin>>u>>v;
		int res=0;
		for(int j=u;j<=v;++j)
		{
			res+=f[j][v];
		}
		cout<<res<<endl;
	}
	return 0;
}