#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int bfs(vector<string> A,int H,int W)
{
	queue<pair<int,int>> que;
	vector<vector<int>> cost(H,vector<int>(W,-1));
	int lp=H*W;
	rep(i,H)
	{
		rep(j,W)
		{
			if(A[i][j]=='#')
			{
				que.push(make_pair(j,i));
				cost[i][j]=0;
				lp--;
			}
		}
	}
	int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	int ret=0;
	while(lp!=0)
	{
		int n=que.size();
		rep(i,n)
		{
			pair<int,int> p=que.front();que.pop();
			for(auto d : dir)
			{
				int x=d[0]+p.first;
				int y=d[1]+p.second;
				if(0>x||x>=W||0>y||y>=H||cost[y][x]!=-1) continue;
				cost[y][x]=0;
				que.push(make_pair(x,y));
			}
		}
		lp-=que.size();
		ret++;
	}
	return ret;
}
int main()
{
	int H,W;
	cin>>H>>W;
	vector<string> A(H);
	rep(i,H)
	{
		cin>>A[i];
	}
	cout<<bfs(A,H,W)<<endl;
	return 0;
}
