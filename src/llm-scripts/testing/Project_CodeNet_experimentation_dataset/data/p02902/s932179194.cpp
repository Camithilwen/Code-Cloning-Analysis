#include <stdio.h>
#include <algorithm>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
vector<int> e[1010];

int v[1010], last[1010];
vector<int> r(2000, 0);
void bfs(int node) {
	queue<int> q;
	for (int x : e[node])
		q.emplace(x), v[x] = last[x] = node;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int x : e[cur])
			if (v[x] != node)
				q.emplace(x), v[x] = node, last[x] = cur;
	}
	if (v[node] != node)
		return;
	int pop = node;
	vector<int> path;
	path.emplace_back(node);
	while (last[pop] != node) {
		path.emplace_back(last[pop]);
		pop = last[pop];
	}
	if (path.size() < r.size())
		r.swap(path);
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		e[a].emplace_back(b);
	}
	for (int i = 1; i <= n; i++)
		bfs(i);
	if (n < r.size())
		printf("-1\n");
	else {
		printf("%d\n", r.size());
		for (int v : r)
			printf("%d\n", v);
	}
}