#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 15;
const int MAXS = (1 << N) + 5;

template <typename T> inline void read(T &AKNOI) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    AKNOI = flag * x;
}

template <typename T> inline void cmax(T &x, T y) {
	if (x < y) x = y;
}

int n, m, S, g[N][N], bin[N], id[MAXS];
int sum[MAXS], dp[MAXS][N];

void init() {
	read(n); read(m);
	S = (1 << n);
	for (int i = 0; i < n; ++i) {
		bin[i] = (1 << i);
		id[bin[i]] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		read(a); read(b); read(c);
		g[a - 1][b - 1] = g[b - 1][a - 1] = c;
	}
	for (int s = 1; s < S; ++s) {
		int u = id[s & (-s)];
		sum[s] = sum[s ^ bin[u]];
		for (int i = u + 1; i < n; ++i) {
			if ((s >> i) & 1) {
				sum[s] += g[u][i];
			}
		}
	}
}

void solve() {
	mset(dp, 0x80);
	int ans = dp[0][0];
	dp[1][0] = 0;
	for (int s = 1; s < S; ++s) {
		for (int i = 0; i < n; ++i) {
			for (int t = s; t; t = (t - 1) & s) {
				if (t & bin[i]) {
					cmax(dp[s][i], dp[s ^ t ^ bin[i]][i] + sum[t]);
				}
			}
			for (int j = 0; j < n; ++j) {
				if ((s >> j) & 1) continue;
				if (!g[i][j]) continue;
				cmax(dp[s | bin[j]][j], dp[s][i] + g[i][j]);
			}
		}
		if (s & bin[n - 1]) {
			cmax(ans, dp[s][n - 1]);
		}
	}
	printf("%d\n", sum[S - 1] - ans);
}

int main() {
	init();
	solve();
	return 0;
}
