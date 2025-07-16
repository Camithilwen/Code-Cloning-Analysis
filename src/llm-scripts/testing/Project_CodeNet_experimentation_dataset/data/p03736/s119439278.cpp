#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const long long inf = 1e18;

int n, MAX, A, B;
int x[N];
long long sum[N];

struct SegmentTree {
	long long T[N << 2], lz[N << 2];
	void init() {
		for (int i = 1; i < (N << 2); ++i) {
			T[i] = inf;
			lz[i] = 0;
		}
	}

	#define mid ((l + r) >> 1)
	void push(int v, int l, int r) {
		if (lz[v] == 0) return;
		if (l < r) lz[v << 1] += lz[v], lz[v << 1 | 1] += lz[v];
		T[v] += lz[v];
		lz[v] = 0;
		if (T[v] > inf) T[v] = inf;
	}

	void upd_pos(int v, int l, int r, int pos, long long val) {
		push(v, l, r);
		if (l > r || r < pos || l > pos) return;
		if (l == r) { T[v] = val; return; }
		upd_pos(v << 1, l, mid, pos, val); upd_pos(v << 1 | 1, mid + 1, r, pos, val);
		T[v] = min(T[v << 1], T[v << 1 | 1]);
	}
	void upd_seg(int v, int l, int r, int L, int R, int val) {
		push(v, l, r);
		if (l > r || R < l || L > r) return;
		if (L <= l && r <= R) { lz[v] = val; push(v, l, r); return; }
		upd_seg(v << 1, l, mid, L, R, val); upd_seg(v << 1 | 1, mid + 1, r, L, R, val);
		T[v] = min(T[v << 1], T[v << 1 | 1]);
	}

	long long get(int v, int l, int r, int L, int R) {
		push(v, l, r);
		if (l > r || R < l || L > r) return inf;
		if (L <= l && r <= R) return T[v];
		return min(get(v << 1, l, mid, L, R), get(v << 1 | 1, mid + 1, r, L, R));
	}
	#undef mid

	void upd_pos(int pos, long long val) { upd_pos(1, 0, MAX, pos, val); }
	void upd_seg(int l, int r, int val) { upd_seg(1, 0, MAX, l, r, val); }
	long long get(int l, int r) { return get(1, 0, MAX, l, r); }
} seg1, seg2;

long long ans = inf;

void solve() {
	//x[0] = B;
	// first move: A
	seg1.init(); // seg1 for xi >= xj (i > j)
	seg2.init(); // seg2 for xi < xj (i > j)
	seg1.upd_pos(B, abs(x[1] - A) - B);
	seg2.upd_pos(B, abs(x[1] - A) + B);

	for (int i = 2; i <= n; ++i) {
		long long cur = min(seg1.get(0, x[i]) + x[i], seg2.get(x[i], MAX) - x[i]);
		seg1.upd_seg(0, MAX, abs(x[i] - x[i-1]));
		seg2.upd_seg(0, MAX, abs(x[i] - x[i-1]));
		seg1.upd_pos(x[i-1], cur - x[i-1]);
		seg2.upd_pos(x[i-1], cur + x[i-1]);
	}
	
	for (int i = 1; i <= MAX; ++i) {
		ans = min(ans, seg1.get(i, i) + i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> MAX >> n >> A >> B; // initial positions
	for (int i = 1; i <= n; ++i) cin >> x[i];
	solve();
	swap(A,B);
	solve();
	printf("%lld\n", ans);
}