#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MN 301000
#define MM 1601000

typedef std::pair<int, int> P;
int h[MN], nxt[MM], to[MM], cost[MM], K = 0;
std::vector<P> v[101000];
int d[MN], n, m;
std::deque<int> q;

void ins(int u, int v, int c) {nxt[++K] = h[u]; h[u] = K; to[K] = v; cost[K] = c;}

int bfs()
{
	q.push_back(1);
	memset(d, 0x3f, sizeof(d)); d[1] = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop_front();
		for(int i = h[u]; i; i = nxt[i])
		{
			if(d[to[i]] > d[u] + cost[i])
			{
				d[to[i]] = d[u] + cost[i];
				if(cost[i]) q.push_back(to[i]);
				else q.push_front(to[i]);
			}
		}
	}
	if(d[n] > 1e9) return -1;
	return d[n];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
	{
		int p, q, c; scanf("%d%d%d", &p, &q, &c);
		v[p].push_back(P(c, i));
		v[q].push_back(P(c, i));
		ins(p, n + i, 1); ins(n + i, p, 0);
		ins(q, n + i, 1); ins(n + i, q, 0);
	}
	for(int i = 1; i <= n; i++)
	{
		std::sort(v[i].begin(), v[i].end());
		int S = v[i].size();
		for(int j = 1; j < S; j++)
		{
			if(v[i][j].first == v[i][j - 1].first)
			{
				ins(v[i][j].second + n, v[i][j - 1].second + n, 0);
				ins(v[i][j - 1].second + n, v[i][j].second + n, 0); 
			}
		}
	}
	printf("%d\n", bfs());
}