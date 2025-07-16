#include <iostream>
#include <queue>
#include <functional>
#include <vector>

using namespace std;

struct edge {
	int to;
	int cost;
};

typedef pair<int, int> P;

int V;
vector<edge> G[3010];
vector<edge> G2[3010];
int d[3010];

void dijkstra(int s, int h) {
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d+V, 10000000);
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first) {
			continue;
		}
		if (h == 0) {
			for (int i = 0; i < G[v].size(); i++) {
				edge e = G[v][i];
				if (d[e.to] > d[v] + e.cost) {
					d[e.to] = d[v] + e.cost;
					que.push(P(d[e.to], e.to));
				}
			}
		} else {
			for (int i = 0; i < G2[v].size(); i++) {
				edge e = G2[v][i];
				if (d[e.to] > d[v] + e.cost) {
					d[e.to] = d[v] + e.cost;
					que.push(P(d[e.to], e.to));
				}
			}
		}
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		for (int i = 1; i <= m; i++) {
			G[i].clear();
			G2[i].clear();
		}
		V = m+1;
		int a, b, time, cost;
		for (int i = 0; i < n; i++) {
			cin >> a >> b >> cost >> time;
			edge e;
			e.to = b;
			e.cost = cost;
			G[a].push_back(e);
			e.to = a;
			G[b].push_back(e);
			e.to = b;
			e.cost = time;
			G2[a].push_back(e);
			e.to = a;
			G2[b].push_back(e);
		}
		int w;
		cin >> w;
		int p, q, r;
		for (int i = 0; i < w; i++) {
			cin >> p >> q >> r;
			dijkstra(p, r);
			cout << d[q] << endl;
		}
	}
	return 0;
}