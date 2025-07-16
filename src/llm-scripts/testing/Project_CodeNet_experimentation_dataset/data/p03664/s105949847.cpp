#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,u,v,w;
ll bismarck[(1<<15)][15],e[15][15],sum[(1<<15)];
int main()
{
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v>>w;
		u--,v--;
		e[u][v]=e[v][u]=w;
	}
	for(int i=0;i<1<<n;i++)
	{
		for(int j=0;j<n;j++){
		if((i>>j)&1)
		{
            for(int k=j+1;k<n;k++)
		    if((i>>k)&1) sum[i]+=e[j][k];			
		}
		bismarck[i][j]=-1e18;}
	}
	bismarck[1][0]=0;
	for(int i=1;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		if((i>>j)&1)
		{
			int l=i^(1<<j);
			for(int k=0;k<n;k++)
			if((i>>k)&1&&e[j][k]) bismarck[i][j]=max(bismarck[i][j],bismarck[l][k]+e[k][j]);
			for(int k=l;k>0;k=(k-1)&l) bismarck[i][j]=max(bismarck[i][j],bismarck[i^k][j]+sum[k^(1<<j)]); 
		}
	}
	cout<<sum[(1<<n)-1]-bismarck[(1<<n)-1][n-1];
}