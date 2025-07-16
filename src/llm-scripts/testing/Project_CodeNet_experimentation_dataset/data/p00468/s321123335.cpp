#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int main() {
	while(cin >> n >> m, n) {
		vector<vector<int> > G(n);
		for(int i = 0; i < m; i++) {
			cin >> a >> b; a--, b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		vector<int> d(n, -1); d[0] = 0;
		queue<int> que; que.push(0);
		while(!que.empty()) {
			int u = que.front(); que.pop();
			for(int i : G[u]) {
				if(d[i] == -1) {
					d[i] = d[u] + 1;
					que.push(i);
				}
			}
		}
		int cnt = -1;
		for(int i = 0; i < n; i++) {
			if(d[i] <= 2) cnt++;
		}
		cout << cnt << endl;
	}
}