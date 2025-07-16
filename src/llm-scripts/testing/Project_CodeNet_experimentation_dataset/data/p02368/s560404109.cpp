#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int> >& G, int& t, vector<int>& ord, vector<int>& low, int& k, vector<int>& cmp, stack<int>& s) {
	ord[u] = low[u] = t++;
	s.push(u);
	for (int v: G[u]) {
		if (ord[v] == -1) {
			dfs(v, G, t, ord, low, k, cmp, s);
			low[u] = min(low[u], low[v]);
		}
		else if (cmp[v] == -1)
			low[u] = min(low[u], ord[v]);
	}
	if (ord[u] == low[u]) {
		for (;;) {
			int v = s.top(); s.pop();
			cmp[v] = k;
			if (v == u) break;
		}
		k++;
	}
}

vector<int> scc(vector<vector<int> >& G) {
	int N = G.size(), t = 0, k = 0;
	vector<int> ord(N, -1), low(N), cmp(N, -1);
	stack<int> s;
	for (int u = 0; u < N; u++)
		if (ord[u] == -1)
			dfs(u, G, t, ord, low, k, cmp, s);
	return cmp;
}

int main() {
	int N; cin >> N;
	vector<vector<int> > G(N);
	int M; cin >> M;
	while (M--) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v);
	}
	vector<int> cmp = scc(G);
	int Q; cin >> Q;
	while (Q--) {
		int u, v; scanf("%d%d", &u, &v);
		printf("%d\n", cmp[u] == cmp[v]);
	}
}