#include <bits/stdc++.h>
using namespace std;

const int N = 16;
const int inf = 1e9;

int n, m;
int e[N][1 << N];
int c[N][N];
int dp[N][1 << N];

void minimize(int &x, int y) { x = (x > y) ? y : x; }

void prep() {
	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int i = 0; i < n; ++i) if (!(mask >> i & 1)) {
			for (int j = 0; j < n; ++j) if (mask >> j & 1) e[i][mask] += c[i][j];
		}
	}
}

void brute(int pos, int cmask, int cost, int &u, int &mask) { 
// dp[u][mask] is the current state
// cmask is the next mask
	if (pos == n) {
		minimize(dp[u][cmask], dp[u][mask] + cost);
		return;
	}
	
	if (mask >> pos & 1) {
		return brute(pos + 1, cmask | (1 << pos), cost, u, mask);
	}

	brute(pos + 1, cmask, cost, u, mask);
	brute(pos + 1, cmask | (1 << pos), cost + e[pos][mask ^ (1 << u)], u, mask);
}

int main() {
	scanf("%d %d", &n, &m);
	while(m--) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		c[u][v] = c[v][u] = w;
	}

	prep();

	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int i = 0; i < n; ++i) dp[i][mask] = inf;
	}

	dp[0][1] = 0;

	for (int mask = 0; mask < (1 << n); ++mask) {
		for (int u = 0; u < n; ++u) if (dp[u][mask] != inf) {
			
			for (int v = 0; v < n; ++v) if (!(mask >> v & 1)) {
				if (c[u][v] == 0) continue;
				minimize(dp[v][mask ^ (1 << v)], dp[u][mask] + e[v][mask ^ (1 << u)]);
			}

			brute(0, 0, 0, u, mask);
		}
	}

	printf("%d\n", dp[n - 1][(1 << n) - 1]);
}