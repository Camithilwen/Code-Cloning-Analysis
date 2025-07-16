#include <iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m;

vector <int> g[15], c[15];
void add_edge(int u, int v, int w) {
	g[u].push_back(v);
	c[u].push_back(w);
}

int dp[1 << 15][15];
int prep[1 << 15][15];

void upd(int &x, int y) {
	if (y < x) x = y;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++ i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		-- u; -- v;
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	memset(dp, 0x3f, sizeof(dp));
	int full = (1 << n) - 1;
	for (int msk = 1; msk < (1 << n); ++ msk) {
		for (int i = 0; i < n; ++ i) if (!(msk >> i & 1)) {
			for (int e = 0; e < g[i].size(); ++ e) {
				if (msk >> g[i][e] & 1) prep[msk][i] += c[i][e];
			}
		}
	}
	dp[1][0] = 0;
	for (int msk = 1; msk < (1 << n); ++ msk) {
		for (int u = 0; u < n; ++ u) if (msk >> u & 1) {
			for (int e = 0; e < g[u].size(); ++ e) {
				int v = g[u][e];
				if (!(msk >> v & 1))
					upd(dp[msk | 1 << v][v], dp[msk][u] + prep[msk ^ 1 << u][v]);
			}
			for (int s = full ^ msk; s; s = (s - 1) & (full ^ msk)) {
				int cur = 0;
				for (int i = 0; i < n; ++ i) if (s >> i & 1)
					cur += prep[msk ^ 1 << u][i];
				upd(dp[msk | s][u], dp[msk][u] + cur);
			}
		}
	}
	printf("%d\n", dp[full][n - 1]);
	return 0;
}