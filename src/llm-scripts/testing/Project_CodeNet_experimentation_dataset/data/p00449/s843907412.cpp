#include "bits/stdc++.h"
#define MOD 1000000007
#define INF 11234567890
#define in std::cin
#define out std::cout
#define rep(i,N) for(int i=0;i<N;++i)
typedef long long int LL;
typedef std::pair<LL, LL> P;
struct edge { LL to, cost; };

LL n, k;
LL d[112];
std::vector<edge>G[112];

void dijkstra(LL s)
{
	std::priority_queue<P, std::vector<P>, std::greater<P>>que;
	std::fill(d, d + n + 1, INF);
	d[s] = 0;
	que.push(P(0, s));
	while (!que.empty())
	{
		P p = que.top(); que.pop();
		LL v = p.second;
		if (d[v] < p.first) { continue; }
		rep(i, G[v].size())
		{
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int main()
{
	while (true)
	{
		n = k = 0;
		memset(d, 0, sizeof(d));
		rep(i, 112) { G[i].clear(); }

		in >> n >> k;
		if (n == 0 && k == 0) { break; }
		rep(loop, k)
		{
			LL flag;
			in >> flag;
			if (flag == 0)
			{
				LL a, b;
				in >> a >> b;
				dijkstra(a);
				out << (d[b] == INF ? -1 : d[b]) << std::endl;
			}
			else
			{
				LL c, d, e;
				in >> c >> d >> e;
				G[c].push_back({ d,e });
				G[d].push_back({ c,e });
			}
		}
	}
	return 0;
}