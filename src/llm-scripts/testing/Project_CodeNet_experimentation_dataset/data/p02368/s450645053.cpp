#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n, m;

vector<int> to[N];

int dfn[N], low[N], bel[N], tim, cnt;

stack<int> stk;
bitset< N > vis;

void tarjan(int u)
{
	dfn[u] = low[u] = ++tim; stk.push(u); vis.set(u);
	
	for (auto v : to[u])
	{
		if (!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (vis[v])
			low[u] = min(low[u], dfn[v]);
	}
	
	if (low[u] == dfn[u])
	{
		int t; ++cnt;
		do
		{
			t = stk.top(); stk.pop();
			bel[t] = cnt; vis.reset(t);
		}
		while (t != u);
	}
}

signed main(void)
{
	cin >> n >> m;
	
	for (int u, v; m--; )
	{
		cin >> u >> v;
		to[u].push_back(v);
	}
	
	for (int i = 0; i < n; ++i)
		if (!dfn[i])tarjan(i);
	
	int q; cin >> q;
	
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		cout << (bel[x] == bel[y]) << endl;
	}
}