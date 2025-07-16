#include <bits/stdc++.h>

typedef std::pair<int, int> pii;

namespace IO {
	const int lim = 1 << 20 | 50;

	char buf[lim + 5], *S, *T;

	inline char gc() {
		if (S == T) {
			T = (S = buf) + fread(buf, 1, lim, stdin);
			if (S == T) return EOF;
		}
		return *S++;
	}

	inline int read() {
		int x; bool f; char c;
		for (f = 0; (c = gc()) < '0' || c > '9'; f = c == '-');
		for (x = c ^ '0'; (c = gc()) >= '0' && c <= '9'; x = x * 10 + c - '0');
		return f ? -x : x;
	}
}

const int MN = 1e5 + 5, MV = 5e5 + 5;

std::map<pii, int> mp;

int n, m, dist[MV], vn;

bool vis[MV];

std::deque<int> q;

std::vector<int> G[MV];

void solve() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0; q.push_back(1);
	for (; !q.empty(); ) {
		int u = q.front(); q.pop_front();
		if (vis[u]) continue; vis[u] = 1;
		for (unsigned int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i];
			if (vis[v] || (dist[u] + (u <= n)) >= dist[v]) continue;
			dist[v] = dist[u] + (u <= n);
			if (u <= n) q.push_back(v);
			else q.push_front(v);
		}
	}
}

int main() {
	vn = n = IO::read();

	for (m = IO::read(); m; --m) {
		int x = IO::read(), y = IO::read(), c = IO::read();
		if (mp.find(pii(x, c)) == mp.end()) {
			mp[pii(x, c)] = ++vn;
			G[vn].push_back(x);
			G[x].push_back(vn);
		}
		if (mp.find(pii(y, c)) == mp.end()) {
			mp[pii(y, c)] = ++vn;
			G[vn].push_back(y);
			G[y].push_back(vn);
		}
		x = mp[pii(x, c)];
		y = mp[pii(y, c)];
		G[x].push_back(y);
		G[y].push_back(x);
	}

	solve();

	printf("%d\n", dist[n] == 0x3f3f3f3f ? -1 : dist[n]);

	return 0;
}
/*
8 11
1 3 1
1 4 2
2 3 1
2 5 1
3 4 3
3 6 3
3 7 3
4 8 4
5 6 1
6 7 5
7 8 5
*/