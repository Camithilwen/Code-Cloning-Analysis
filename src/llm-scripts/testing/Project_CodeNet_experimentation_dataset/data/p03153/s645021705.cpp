#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const ll linf = 1e18 + 7;

struct segment_tree {
	static const int maxn = 1 << 18;
	pair <ll, int> mn[maxn << 1];
	void init() {
		for (int i = 1; i < (maxn << 1); ++ i)
			mn[i] = mp(linf, -1);
	}
	void upd(int x, ll v) {
		mn[x + maxn] = mp(v, x);
		for (x += maxn; x >>= 1; )
			mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
	}
	pair <ll, int> qry(int l, int r) {
		pair <ll, int> ans = mp(linf, -1);
		for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans = min(ans, mn[l ++]);
			if (r & 1) ans = min(ans, mn[-- r]);
		}
		return ans;
	}
} seg0, seg1;

struct union_find {
	static const int maxn = 2e5 + 5;
	int fa[maxn];
	vector <int> v[maxn];
	void init() {
		for (int i = 0; i < maxn; ++ i)
			fa[i] = i, v[i].pb(i);
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
	void merge(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return ;
		if (v[x].size() < v[y].size()) swap(x, y);
		for (int i = 0; i < v[y].size(); ++ i) v[x].pb(v[y][i]);
		fa[y] = x;
	}
} dsu;

const int maxn = 2e5 + 5;
int n, d, a[maxn];

int main() {
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; ++ i)
		scanf("%d", &a[i]);
	dsu.init();
	seg0.init(); seg1.init();
	for (int i = 0; i < n; ++ i) {
		seg0.upd(i, a[i] - 1LL * d * i);
		seg1.upd(i, a[i] + 1LL * d * i);
	}
	ll ans = 0;
	while (dsu.v[dsu.find(0)].size() != n) {
		vector <pair <ll, pair <int, int> > > e;
		for (int i = 0; i < n; ++ i) {
			if (dsu.find(i) == i) {
//				eprintf("%d\n", i);
				for (int j = 0; j < dsu.v[i].size(); ++ j) {
					int x = dsu.v[i][j];
//					eprintf("%d ", x);
					seg0.upd(x, linf);
					seg1.upd(x, linf);
				}
//				eprintf("\n");
				pair <ll, pair <int, int> > mn = mp(linf, mp(-1, -1));
				for (int j = 0; j < dsu.v[i].size(); ++ j) {
					int x = dsu.v[i][j];
					pair <ll, int> to = seg0.qry(0, x);
					to.first += a[x] + 1LL * d * x;
					mn = min(mn, mp(to.first, mp(x, to.second)));
				}
				for (int j = 0; j < dsu.v[i].size(); ++ j) {
					int x = dsu.v[i][j];
					pair <ll, int> to = seg1.qry(x + 1, n);
					to.first += a[x] - 1LL * d * x;
					mn = min(mn, mp(to.first, mp(x, to.second)));
				}
				e.pb(mn);
				for (int j = 0; j < dsu.v[i].size(); ++ j) {
					int x = dsu.v[i][j];
					seg0.upd(x, a[x] - 1LL * d * x);
					seg1.upd(x, a[x] + 1LL * d * x);
				}
			}
		}
		for (int i = 0; i < e.size(); ++ i) {
			int u = e[i].second.first;
			int v = e[i].second.second;
			ll cost = e[i].first;
			if (!dsu.same(u, v)) {
				dsu.merge(u, v);
				ans += cost;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
