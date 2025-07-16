#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector< vector<int> > VVI;

struct edge {
	int to, cost;
	edge(int t, int c) :to(t), cost(c) {}
};
typedef pair<int, int> P; // firstは最短距離, secondは頂点の番号

const int INF = (1e9);

void wFloyd ( VVI &v )
{
	int len = v.size();

	for (int k = 0; k < len; ++k)
	{
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
}

int dijkstra ( int s, int e, int size, vector< vector<edge> > &graph )
{
	priority_queue< P, vector<P>, greater<P> > que;
	vector<int> cost(size, INF);

	cost[s] = 0;
	que.push(P(0, s));

	while (!que.empty())
	{
		P p = que.top(); que.pop();
		int v = p.second;

		if (cost[v] < p.first) continue;

		for (int i = 0, ilen = graph[v].size(); i < ilen; ++i)
		{
			edge e = graph[v][i];
			if (cost[e.to] > (cost[v] + e.cost))
			{
				cost[e.to] = cost[v] + e.cost;
				que.push(P(cost[e.to], e.to));
			}
		}
	}

	return cost[e];
}

int main ( void )
{
	int n, k;

	while (cin >> n >> k, (n | k))
	{
		//VVI v(n, vector<int>(n, INF));
		vector< vector<edge> > v(n);

		for (int i = 0; i < k; ++i)
		{
			int x;

			cin >> x;

			if (x)
			{
				int c, d, e;

				cin >> c >> d >> e;

				--c; --d;

				bool hit = false;

				for (int j = 0, jlen = v[c].size(); j < jlen && !hit; ++j)
				{
					if ((v[c][j].to == d) && (v[c][j].cost > e))
					{
						v[c][j].cost = e;
						hit = true;
					}
				}

				if (!hit) v[c].push_back(edge(d, e));

				hit = false;

				for (int j = 0, jlen = v[d].size(); j < jlen && !hit; ++j)
				{
					if ((v[d][j].to == c) && (v[d][j].cost > e))
					{
						v[d][j].cost = e;
						hit = true;
					}
				}

				if (!hit) v[d].push_back(edge(c, e));

				//v[c].push_back(edge(d, e));
				//v[d].push_back(edge(c, e));
				
				//if ((v[c][d] > e) || (v[d][c] > e))
				//{
				//	v[c][d] = v[d][c] = e;
				//	wFloyd(v);
				//}
			}
			else
			{
				int a, b;

				cin >> a >> b;

				--a; --b;

				int cost = dijkstra(a, b, n, v);

				if (cost == INF)
				{
					cout << -1 << endl;
				}
				else
				{
					cout << cost << endl;
				}

				//if (v[a][b] == INF)
				//{
				//	cout << -1 << endl;
				//}
				//else
				//{
				//	cout << v[a][b] << endl;
				//}
			}
		}
	}

	return 0;
}