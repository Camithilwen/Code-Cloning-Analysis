#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

vector<int> adj[MAX];
int visited[MAX];
int graph[MAX][MAX];

vector<int> dfs(int v, int root)
{
	vector<int> ans;
	visited[v] = 1;
	if (v != root)
	{
		for (int i : adj[v])
		{
			if (i != root && visited[i]) return ans;
		}
		if (graph[v][root])
		{
			ans.push_back(v);
			return ans;
		}
	}
	for (int i : adj[v])
	{
		vector<int> res = dfs(i, root);
		if (!res.empty())
		{
			int flag = 1;
			for (int j : res)
			{
				if (graph[v][j] && i != j)
				{
					flag = 0;
					break;
				}
			}
			if (!flag) continue;
			res.push_back(v);
			return res;
		}
	}
	visited[v] = 0;
	return ans;
}

int main(void)
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back(v);
		graph[u][v] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) visited[j] = 0;
		vector<int> res = dfs(i, i);
		reverse(res.begin(), res.end());
		if (!res.empty())
		{
			cout << res.size() << endl;
			for (int j : res) cout << j + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
