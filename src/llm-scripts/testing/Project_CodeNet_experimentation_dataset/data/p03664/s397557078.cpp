#include <bits/stdc++.h>

#define ln                '\n'
#define all(dat)           dat.begin(), dat.end()
#define loop(i, to)        for (int i = 0; i < to; ++i)
#define cont(i, to)        for (int i = 1; i <= to; ++i)
#define circ(i, fm, to)    for (int i = fm; i <= to; ++i)
#define foreach(i, dat)    for (__typeof(dat.begin()) i = dat.begin(); i != dat.end(); ++i)

typedef long long          num;

using namespace std;

const int nsz = 15, msksz = (1 << nsz) - 1, inf = 0x3f3f3f3f;
int n, m, full, lg[msksz + 5], g[nsz + 5], w[nsz + 5][nsz + 5], sum[msksz + 5], dp[msksz + 5][nsz + 5];

int inline at(int S, int id) { return S >> id & 1; }

int inline lowbit(int S) { return S & -S; }

string inline bin(int S, int len = n) {
	string s;
	loop (i, len) s += at(S, i) + 48;
	return s;
}

void inline upd(int &a, int b) { if (a < b) a = b; }

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	full = (1 << n) - 1;
	cont (i, m) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		g[u] |= 1 << v;
		g[v] |= 1 << u;
		::w[u][v] = ::w[v][u] = w;
	}
	loop (i, n) lg[1 << i] = i;
	
	memset(sum, -inf, sizeof(sum));
	sum[0] = 0;
	cont (S, full) {
		int u = lg[lowbit(S)];
		sum[S] = sum[S - lowbit(S)];
		for (int t = g[u] & S, d = t & -t; d; t -= d, d = t & -t) {
			int v = lg[d];
			sum[S] += w[u][v];
		}
	}
	memset(dp, -inf, sizeof(dp));
	cont (S, full) {
		if (!at(S, 0) || at(S, n - 1)) continue;
		dp[S][0] = sum[S];
	}
	circ (S, 0, full) {
		for (int rS = (S ^ full), T = rS; T; T = (T - 1) & rS) {
			if (sum[T] < 0) continue;
			for (int t = S, d = t & -t; d; t -= d, d = t & -t) {
				int u = lg[d];
				if (dp[S][u] < 0) continue;
				for (int t = T & g[u], d = t & -t; d; t -= d, d = t & -t) {
					int v = lg[d];
					upd(dp[S | T][v], dp[S][u] + sum[T] + w[u][v]);
				}
			}
		}
	}
	cout << sum[full] - dp[full][n - 1] << ln;
}