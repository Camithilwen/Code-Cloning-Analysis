#include <bits/stdc++.h>
#define enter putchar('\n')
#define space putchar(' ')
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;
vector<pii> E[500005];
set<pii> s;
int n, m, ncnt, d[500005], id[500005][2];
struct EDGE {
	int l, r, c;
} e[200005];
template <class T> int read(T &x) {
	x = 0; int f = 1; char c = getchar();
	while (c > -1 && c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	if (c == -1) return 0;
	while (c >= '0' && c <= '9') { x = x * 10 + c - 48; c = getchar(); }
	return x *= f, 1;
}
template <class T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
bool cmp(EDGE a, EDGE b) {
	return a.c < b.c;
}
int main() {
	while (read(n), read(m)) {
		ncnt = n;
		for (int i = 1; i <= n; ++i)
			E[i].clear();
		for (int i = 1; i <= m; ++i)
			read(e[i].l), read(e[i].r), read(e[i].c);
		sort(e + 1, e + m + 1, cmp);
		for (int i = 1; i <= n; ++i)
			id[i][0] = 0;
		for (int i = 1; i <= m; ++i) {
			if (id[e[i].l][0] != e[i].c) {
				id[e[i].l][0] = e[i].c;
				id[e[i].l][1] = ++ncnt;
				E[ncnt].clear();
				E[ncnt].pb(mp(e[i].l, 1));
				E[e[i].l].pb(mp(ncnt, 1));
			}
			if (id[e[i].r][0] != e[i].c) {
				id[e[i].r][0] = e[i].c;
				id[e[i].r][1] = ++ncnt;
				E[ncnt].clear();
				E[ncnt].pb(mp(e[i].r, 1));
				E[e[i].r].pb(mp(ncnt, 1));
			}
			E[id[e[i].l][1]].pb(mp(id[e[i].r][1], 0));
			E[id[e[i].r][1]].pb(mp(id[e[i].l][1], 0));
		}
		fill(d, d + ncnt + 1, -1);
		d[1] = 0;
		s.insert(mp(d[1], 1));
		while (!s.empty()) {
			int u = s.begin() -> se;
			s.erase(s.begin());
			for (int i = 0; i < E[u].size(); ++i) {
				int v = E[u][i].fi;
				if (d[v] > d[u] + E[u][i].se || d[v] == -1) {
					s.erase(mp(d[v], v));
					d[v] = d[u] + E[u][i].se;
					s.insert(mp(d[v], v));
				}
			} 
		}
		write(d[n] >> 1), enter;
	}
	return 0;
}