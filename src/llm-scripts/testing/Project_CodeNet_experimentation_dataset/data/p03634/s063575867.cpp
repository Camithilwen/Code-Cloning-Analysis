#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 100010
#define INFTY 1e18
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;
struct edge{ll to, cost;};

ll n;
ll dist[MAX];
bool check[MAX];
vector<edge> G[MAX];
void dijkstra(ll s)
{
	priority_queue<P, vector<P>, greater<P>> pq;

	for(ll i = 0; i < n; i++)
	{
		dist[i] = INFTY;
		check[i] = false;
	}

	pq.push(P(0, s));
	dist[s] = 0;
	while (!pq.empty())
	{
		P p = pq.top(); pq.pop();
		ll minv = p.first;
		ll u = p.second;
		check[u] = true;
		if (dist[u] < minv) continue;
		rep(i, G[u].size())
		{
			if (check[G[u][i].to]) continue;
			if (dist[G[u][i].to] > dist[u] + G[u][i].cost)
			{
				dist[G[u][i].to] = dist[u] + G[u][i].cost;
				pq.push(P(dist[G[u][i].to], G[u][i].to));
			}
		}
	}
}

signed main(void)
{
	cin >> n;
	rep(i, n - 1)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--; b--;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
	}
	int q, k;
	cin >> q >> k;
	k--;
	dijkstra(k);
	rep(i, q)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		cout << dist[x] + dist[y] << endl;
	}
	return 0;
}
