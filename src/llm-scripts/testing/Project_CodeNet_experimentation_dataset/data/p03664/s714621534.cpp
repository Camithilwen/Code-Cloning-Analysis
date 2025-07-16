#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
using namespace std;
int n,m;
int dis[16][16];
int dp[1<<16][16];
int subres[1<<16];
int sum;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		x--;y--;
		dis[x][y]=dis[y][x]=z;
		sum+=z;
	}
	for(int i=1;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>>j&1)
			{
				for(int k=j+1;k<n;k++)
				{
					if(i>>k&1)subres[i]+=dis[j][k];
				}
			}
		}
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)dp[i][j]=-1;
	}
	for(int i=1;i+1<(1<<n);i++)
	{
		if(i>>(n-1)&1)continue;
		if(i&1)
		{
			dp[i][0]=0;
			for(int j=0;j<n;j++)
			{
				if(i>>j&1)
				{
					for(int k=j+1;k<n;k++)
					{
						if(i>>k&1)dp[i][0]+=dis[j][k];
					}
				}
			}
		}
	}
	for(int i=1;i+1<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(dp[i][j]==-1)continue;
			int st=((1<<n)-1)^i;
			if(dis[j][n-1])
			{
				dp[(1<<n)-1][n-1]=max(dp[(1<<n)-1][n-1],dp[i][j]+subres[st]+dis[j][n-1]);
			}
			for(int k=(st-1)&st;k;k=(k-1)&st)
			{
				if(k>>(n-1)&1)continue;
				for(int l=0;l<n;l++)
				{
					if(k>>l&1)
					{
						if(dis[j][l])
						{
							dp[i|k][l]=max(dp[i|k][l],dp[i][j]+subres[k]+dis[j][l]);
						}
					}
				}
			}
		}
	}
	printf("%d",sum-dp[(1<<n)-1][n-1]);
	return 0;
}