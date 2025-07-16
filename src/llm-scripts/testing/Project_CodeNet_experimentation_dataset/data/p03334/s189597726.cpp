#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <queue>
#include <vector>

using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int n,D1,D2,id[650][650],col[400000][3];

vector <pair <int,int>> d[3];

inline void dfs(int u,int c)
{
	int x=(u-1)/(2*n)+1,y=(u-1)%(2*n)+1;
	//cout << x << " " << y << endl;
	for (int i=0;i<d[c].size();i++)
	{
		pair <int,int> rhs=d[c][i];
		int nx=x+rhs.first,ny=y+rhs.second;
		if (nx>=1 && nx<=2*n && ny>=1 && ny<=2*n)
		{
			int rid=id[nx][ny];
			if (!col[rid][c])
			{
				col[rid][c]=col[u][c]==1?2:1;
				dfs(rid,c);
			}
		}
	}
}

int main()
{
	n=read(),D1=read(),D2=read();
	for (int i=0;i<=D1;i++)
	{
		int j=sqrt(D1-i*i);
		if (i*i+j*j==D1)
		{
			d[1].push_back({i,j});
			d[1].push_back({-i,j});
			d[1].push_back({i,-j});
			d[1].push_back({-i,-j});
			//if (i!=0)
			//	break;
		}
	}
	for (int i=0;i<=D2;i++)
	{
		int j=sqrt(D2-i*i);
		if (i*i+j*j==D2)
		{
			d[2].push_back({i,j});
			d[2].push_back({-i,j});
			d[2].push_back({i,-j});
			d[2].push_back({-i,-j});
			//if (i!=0)
			//	break;
		}
	}
	for (int i=1;i<=n*2;i++)
	{
		for (int j=1;j<=n*2;j++)
			id[i][j]=(i-1)*2*n+j;
	}
	for (int i=1;i<=n*2;i++)
	{
		for (int j=1;j<=n*2;j++)
		{
			int rhs=id[i][j];
			if (!col[rhs][1])
			{
				col[rhs][1]=1;
				dfs(rhs,1);
			}
			if (!col[rhs][2])
			{
				col[rhs][2]=1;
				dfs(rhs,2);
			}
		}
	}
	int cnt=0;
	for (int i=1;i<=n*2;i++)
	{
		for (int j=1;j<=n*2;j++)
		{
			int rid=id[i][j];
			if (col[rid][1]==1 && col[rid][2]==1)
			{
				cout << i-1 << " " << j-1 << endl;
				cnt++;
			}
			if (cnt==n*n)
				return 0;
		}
	}
	return 0;
}
