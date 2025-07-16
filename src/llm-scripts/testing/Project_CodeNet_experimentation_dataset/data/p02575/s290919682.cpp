#include <cstdio>
#include <iostream>
#include <vector>

#define lson (idx << 1)
#define rson (idx << 1 | 1)
#define INF 1000000000000LL
#define MAXN 200010

using namespace std;
typedef long long ll;
// `lo` is the current minimum of the segment.
// `lh` is the current value of the left endpoint.
// `lazy` is the lazy tag for addition.
struct Node {
	int l, r;
	ll lo;
	bool flag = false;
} s[MAXN << 2];
int h, w;
// Push up
void calc(int idx) {
	s[idx].lo = min(s[lson].lo, s[rson].lo);
}
void build(int idx, int l, int r) {
	s[idx].l = l, s[idx].r = r;
	if (l == r)	return;
	int mid = (l + r) >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
}
// Lazy propagation
void pushdown(int idx) {
	if (s[idx].flag) {
		ll L = s[idx].lo;
		int l = s[idx].l;
		for (int i = lson; i <= rson; ++i) {
			s[i].lo = L + s[i].l - l;
			s[i].flag = true;
		}
	}
	s[idx].flag = false;
}
// Assign segment [l, r] according to f[l-1] = L
void update(int idx, int l, int r, ll L) {
  if (s[idx].l >= l && s[idx].r <= r) {
    s[idx].lo = L + s[idx].l - l + 1;
    s[idx].flag = true;
    return;
  }
  pushdown(idx);
  int mid = (s[idx].l + s[idx].r) >> 1;
  if (l <= mid)
    update(lson, l, r, L);
  if (mid + 1 <= r)
    update(rson, l, r, L);
  calc(idx);
}
// Range minimum query
ll query(int idx, int l, int r) {
	if (r < 1 || l > w)
		return INF;
	if (s[idx].l >= l && s[idx].r <= r)
		return s[idx].lo;
	pushdown(idx);
	ll ans = INF;
	int mid = (s[idx].l + s[idx].r) >> 1;
	if (l <= mid)
		ans = min(ans, query(lson, l, r));
	if (mid + 1 <= r)
		ans = min(ans, query(rson, l, r));
	return ans;
}
void solve() {
	scanf("%d%d",&h,&w);
	vector<int> l(h), r(h);
	for (int i = 0; i < h; ++i)
		scanf("%d%d",&l[i],&r[i]);
	vector<ll> ans(h, INF);
	build(1, 1, w);
	for (int i = 0; i < h; ++i) {
		ll L = query(1, l[i] - 1, l[i] - 1);
		update(1, l[i], r[i], L);
		ans[i] = min(ans[i], query(1, 1, w))+i+1;
		if (ans[i] == INF)	break;
	}
	for (ll i : ans)	cout << (i >= INF ? -1 : i) << endl;
}
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	solve();
}