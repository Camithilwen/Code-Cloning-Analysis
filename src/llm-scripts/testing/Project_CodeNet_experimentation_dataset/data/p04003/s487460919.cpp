#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
typedef pair<int, int> P;
typedef pair<ll, P> PP;
int main() {
	int N, M;
	cin >> N >> M;
	map<P, vector<PP>> G;
	map<P, ll> dist;
	for (int i = 0; i < M; i++) {
		int p, q;
		ll c;
		cin >> p >> q >> c;
		p--; q--;
		G[P(p, 0)].emplace_back(1, P(p, c));
		G[P(p, c)].emplace_back(0, P(p, 0));
		G[P(q, 0)].emplace_back(1, P(q, c));
		G[P(q, c)].emplace_back(0, P(q, 0));
		G[P(p, c)].emplace_back(0, P(q, c));
		G[P(q, c)].emplace_back(0, P(p, c));
	}
	priority_queue<PP, vector<PP>, greater<PP>> Q;
	dist[P(0, 0)] = 0;
	Q.push(PP(0, P(0, 0)));
	while (!Q.empty()) {
		PP now = Q.top(); Q.pop();
		if (dist[now.second] < now.first) continue;
		for (auto e : G[now.second]) {
			if (dist.find(e.second) == dist.end() || dist[e.second] > now.first + e.first) {
				dist[e.second] = now.first + e.first;
				Q.push(PP(dist[e.second], e.second));
			}
		}
	}
	if (dist.find(P(N - 1, 0)) == dist.end()) {
		cout << -1 << endl;
		return 0;
	}
	cout << dist[P(N - 1, 0)] << endl;
}
