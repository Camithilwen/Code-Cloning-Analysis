#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define x first
#define y second

namespace QAQ
{
	typedef std::pair<int,int> pii;

	const int N=303;

	int type[N*2][N*2];
	int n,d0,d1;

	bool vis[N*2][N*2];
	std::vector<pii> mv;

	void dfs(int nx,int ny,int val,int cur=0)
	{
		if(nx<0 || ny<0 || nx>=n*2 || ny>=n*2 || vis[nx][ny])return;

		vis[nx][ny]=1,type[nx][ny]^=cur,cur^=val;

		for(int i=0;i<(int)mv.size();i++)
			dfs(nx+mv[i].x,ny+mv[i].y,val,cur);
	}

	void work(int dis,int val)
	{
		mv.resize(0);
		for(int i=0;i*i<=dis;i++)
			for(int j=0;i*i+j*j<=dis;j++)
				if(i*i+j*j==dis)
				{
					mv.push_back(pii(i,j));
					mv.push_back(pii(-i,j));
					mv.push_back(pii(i,-j));
					mv.push_back(pii(-i,-j));
				}

		memset(vis,0,sizeof(vis));
		for(int i=0;i<n*2;i++)
			for(int j=0;j<n*2;j++)
				if(!vis[i][j])dfs(i,j,val);
	}
	std::vector<pii> ans[4];
	void solve()
	{
		scanf("%d%d%d",&n,&d0,&d1);
		work(d0,1),work(d1,2);

		for(int i=0;i<n*2;i++)
			for(int j=0;j<n*2;j++)
				ans[type[i][j]].push_back(pii(i,j));
		int ind=0;
		for(int i=1;i<4;i++)
			if(ans[i].size()>ans[ind].size())ind=i;

		if((int)ans[ind].size()<n*n)printf("O_O\n");

		for(int i=0;i<n*n;i++)
			printf("%d %d\n",ans[ind][i].x,ans[ind][i].y);
	}
}

int main()
{
	QAQ::solve();
	return 0;
}
