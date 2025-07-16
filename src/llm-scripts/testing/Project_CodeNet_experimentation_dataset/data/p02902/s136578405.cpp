#include<bits/stdc++.h>
using namespace std;
const int N = 1003;
int n, m, dis[N], par[N];
vector<int> adj[N], ans;
int main(int argc, char const *argv[])
{
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		scanf("%d %d\n", &u, &v);
		adj[u].push_back(v);
	}
	for (int s = 1; s <= n; ++s)
	{
		queue<int> q;
		for (int i = 1; i <= n; ++i)
		{
			par[i] = dis[i] = -1;
		}
		q.push(s);
		dis[s] = 0;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int v: adj[u])
			{
				if (dis[v] == -1)
				{
					par[v] = u;
					dis[v] = 1 + dis[u];
					q.push(v);
				}
				else if (v == s)
				{
					int cur = u;
					vector<int> temp;
					while (cur != -1)
					{
						temp.push_back(cur);
						cur = par[cur];
					}
					if (temp.size() < ans.size() || ans.empty())
					{
						ans.clear();
						for (int node: temp)
							ans.push_back(node);
					}
				}
			}
		}
	}
	if (ans.empty())
		printf("%d\n", -1);
	else
	{
		printf("%d\n", (int)ans.size());
		for (int node: ans)
			printf("%d\n", node);
	}
	return 0;
}