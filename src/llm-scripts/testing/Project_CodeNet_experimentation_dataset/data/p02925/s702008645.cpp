#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<P> G[1001][1001];
int dp[1001][1001];

vector<P> tp;

int dfs(int x,int y,int px=1000,int py=1000)
{
	if(dp[x][y]!=0)return dp[x][y];
	if(G[x][y].empty())return dp[x][y] = 1;
	for(auto i:G[x][y])
	{
		dp[x][y] = max(dp[x][y],dfs(i.first,i.second,x,y)+1);
	}
	return dp[x][y];
}


int main()
{
	int n;
	cin >> n;
	vector<vector<P>> input(n);
	map<P,int> h;//入次数
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n-1;j++)
		{
			int x=i;
			int y;
			cin >> y;
			y--;
			if(x>y)swap(x,y);
			input[i].emplace_back(x,y);

		}
	}
	for(int i = 0;i<n;i++)
	{
		for(int j =0;j<n-2;j++)
		{
			h[input[i][j+1]]++;
			G[input[i][j].first][input[i][j].second].emplace_back(input[i][j+1]);
		}
	}
	stack<P> S; //入次数がゼロの頂点
	for(int i = 0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			if(h[P(i,j)]==0)
			{
				S.emplace(i,j);
			}
		}
	}
	while(S.size())
	{
		auto now = S.top();S.pop();
		tp.push_back(now);
		for(auto i:G[now.first][now.second])
		{
			h[i]--;
			if(h[i]==0)S.emplace(i);
		}
	}
	if(tp.size()!=n*(n-1)/2)
	{
		cout << -1 << endl;
		return 0;
	}



	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		for(int j = i+1;j<n;j++)
		{
			ans = max(ans,dfs(i,j));
		}
	}
	cout << ans << endl;
}
