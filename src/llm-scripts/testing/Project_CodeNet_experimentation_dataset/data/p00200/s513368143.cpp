#include <bits/stdc++.h>
using namespace std;
struct edge { int to, cost; };
bool operator<(const edge& e1, const edge& e2) { return e1.cost < e2.cost; }
int n, m, a1, a2, a3, a4, q;
int main() {
	while(cin >> m >> n, n | m) {
		vector<vector<edge> > G1(n), G2(n);
		for(int i = 0; i < m; i++) {
			cin >> a1 >> a2 >> a3 >> a4; a1--, a2--;
			G1[a1].push_back(edge{a2, a3});
			G1[a2].push_back(edge{a1, a3});
			G2[a1].push_back(edge{a2, a4});
			G2[a2].push_back(edge{a1, a4});
		}
		cin >> q;
		while(q--) {
			cin >> a1 >> a2 >> a3; a1--, a2--;
			if(a3 == 0) {
				priority_queue<edge> que; que.push(edge{a1, 0});
				vector<int> d(n, 999999999); d[a1] = 0;
				while(!que.empty()) {
					int u = que.top().to; que.pop();
					for(edge e: G1[u]) {
						if(d[e.to] > d[u] + e.cost) {
							d[e.to] = d[u] + e.cost;
							que.push(edge{e.to, -d[e.to]});
						}
					}
				}
				cout << d[a2] << endl;
			}
			else {
				priority_queue<edge> que; que.push(edge{a1, 0});
				vector<int> d(n, 999999999); d[a1] = 0;
				while(!que.empty()) {
					int u = que.top().to; que.pop();
					for(edge e: G2[u]) {
						if(d[e.to] > d[u] + e.cost) {
							d[e.to] = d[u] + e.cost;
							que.push(edge{e.to, -d[e.to]});
						}
					}
				}
				cout << d[a2] << endl;
			}
		}
	}
}