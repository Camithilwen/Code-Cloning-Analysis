#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 1005;
int id[MAX_N][MAX_N],A[MAX_N][MAX_N],dp[MAX_N*MAX_N];
bool visit[MAX_N*MAX_N],calc[MAX_N*MAX_N];
vector<int> G[MAX_N*MAX_N];

void init()
{
	rep(i,MAX_N)
	{
		rep(j,MAX_N)
		{
			id[i][j] = -1;
		}
	}
	rep(i,MAX_N*MAX_N)
	{
		dp[i] = 1;
		visit[i] = false;
		calc[i] = false;
	}
	return;
}

int getid(int a, int b)
{
	if (a > b) swap(a,b);
	return id[a][b];
}

int dfs(int n)
{
	//cout << "visiting:" << n << endl;
	if (visit[n])
	{
		//cout << "b";
		if (!calc[n]) return -1;
		return dp[n];
	}
	visit[n] = true;
	int res;
	rep(i,G[n].size())
	{
		res = dfs(G[n][i]);
		if (res == -1) 
		{
			//cout << "c";
			return -1;
		}
		dp[n] = max(dp[n],res+1);
	}
	calc[n] = true;
	//cout << "return:" << dp[n] << endl;
	return dp[n];
}

int main()
{
	init();
	int N;
	cin >> N;
	int cnt = 0;
	rep(i,N)
	{
		rep(j,N-1)
		{
			int idx = i+1;
			cin >> A[i][j];
			if (getid(idx,A[i][j]) == -1)
			{
				if (idx > A[i][j]) id[A[i][j]][idx] = cnt;
				else id[idx][A[i][j]] = cnt;
				cnt++;
			}
			if (j > 0)
			{
				G[getid(idx,A[i][j-1])].push_back(getid(idx,A[i][j]));
			}
		}
	}
	/*
	rep(i,N)
	{
		rep(j,N)
		{
			if (i == j) cout << "  ";
			else cout << getid(i+1,j+1) << " ";
		}
		cout << endl;
	}
	rep(i,N)
	{
		rep(j,G[i].size())
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
	*/
	int ans = 0;
	rep(i,N*(N-1)/2)
	{
		int res = dfs(i);
		if (res == -1)
		{
			cout << "-1" << endl;
			return 0;
		}
		ans = max(ans,res);
	}
	cout << ans << endl;
	return 0;
}