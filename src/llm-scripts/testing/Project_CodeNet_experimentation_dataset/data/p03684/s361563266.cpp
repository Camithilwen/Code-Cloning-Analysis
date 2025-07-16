#include <bits/stdc++.h>
#define N 200001
using namespace std;

typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ul;

struct point { int x, y; } ps[N];

ui fs[N];
ui uf(ui x) { return fs[x] ? fs[x] = uf(fs[x]) : x; }
bool uu(ui x, ui y) {
	x = uf(x); y = uf(y);
	if (x != y) fs[x] = y;
	return x != y;
}

ui p[N];

struct edge { ui u, v, w; };
bool operator<(edge e1, edge e2) { return e1.w < e2.w; }
ui dis(ui u, ui v) { return min(abs(ps[u].x - ps[v].x), abs(ps[u].y - ps[v].y)); }

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
#ifdef _DEBUG
	ifstream cin("1.in");
#endif
	ui n; cin >> n;
	ul ans = 0;
	for (ui i = 1; i <= n; ++i) cin >> ps[i].x >> ps[i].y;
	iota(p, p + n, 1);
	vector<edge> ev;

	sort(p, p + n, [](ui i1, ui i2) { return ps[i1].x < ps[i2].x; });
	ui i = 0;
	while(i != n - 1) {
		ui u = p[i], v = p[i + 1];
		if (ps[u].x == ps[v].x) uu(u, v);
		else ev.push_back({ u, v, dis(u, v) });
		++i;
	}

	sort(p, p + n, [](ui i1, ui i2) { return ps[i1].y < ps[i2].y; });
	i = 0;
	while(i != n - 1) {
		ui u = p[i], v = p[i + 1];
		if (ps[u].y == ps[v].y) uu(u, v);
		else ev.push_back({ u, v, dis(u, v) });
		++i;
	}

	sort(ev.begin(), ev.end());
	for (edge e : ev)
		if (uu(e.u, e.v))
			ans += e.w;

	cout << ans << endl;
	return 0;
}