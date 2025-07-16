#include <bits/stdc++.h>
using namespace std;
const int M = 1e6;
set<int> adj[M];
int nd, indeg[M];
bool vis[M];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	map<pair<int, int>, int > mp;
	int mat[n][n - 1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			cin >> mat[i][j];
			mat[i][j]--;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 2; j++) {
			pair<int, int> p1 = {i, mat[i][j]}, p2 = {i, mat[i][j + 1]};
			if (p1.first > p1.second)
				swap(p1.first, p1.second);
			if (p2.first > p2.second)
				swap(p2.first, p2.second);
			if (mp.find(p1) == mp.end())
				mp[p1] = nd++;
			if (mp.find(p2) == mp.end())
				mp[p2] = nd++;
			if (adj[mp[p1]].find(mp[p2]) == adj[mp[p1]].end()) {
				adj[mp[p1]].insert(mp[p2]);
				indeg[mp[p2]]++;
			}
		}
	}
	queue<pair<int, int> > q;
	for (int i = 0; i < nd; i++) {
		if (indeg[i] == 0) {
			vis[i] = true;
			q.push({i, 1});
		}
	}
	int ans = -1;
	while (!q.empty()) {
		int v = q.front().first, d = q.front().second;
		q.pop();
		for (auto nbr : adj[v])
			indeg[nbr]--;
		ans = d;
		for (auto nbr : adj[v]) {
			if (!vis[nbr] && indeg[nbr] == 0) {
				vis[nbr] = true;
				q.push({nbr, d + 1});
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i])
			ans = -1;
	}
	cout << ans;
	return 0;
}