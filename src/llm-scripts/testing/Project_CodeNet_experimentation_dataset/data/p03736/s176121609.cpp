#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++i)
#define dep(i, j, k) for(int i = j; i >= k; --i)
#define enter putchar('\n')
#define fi first
#define se second
#define mp(x, y) make_pair(x, y)

typedef long long ll;

using namespace std;

const int maxn = 3e5 + 5;
const int LOG = 35;
const int inf = 0x3f3f3f3f;

int n, m, a[maxn];

inline int read() {
	char ch = getchar(); int u = 0, f = 1;
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch))  { u = u * 10 + ch - 48; ch = getchar(); } return u * f;
}

struct SEG {
	#define ls p << 1
	#define rs p << 1 | 1
	#define mid (l + r >> 1)
	struct Node {
		ll mn, tag;
		Node() { tag = 0; mn = (1ll << 60); }
	} t[maxn << 2];

	inline void pushtag(int p, ll x) {
		t[p].tag += x; t[p].mn += x;
	}

	inline void pushdown(int p) {
		if(t[p].tag) {
			pushtag(ls, t[p].tag);
			pushtag(rs, t[p].tag);
			t[p].tag = 0;
		}
	}

	inline void modify(int l, int r, int pos, int p, ll x) {
		if(l == r) { t[p].mn = min(t[p].mn, x); return; }
		pushdown(p);
		if(pos <= mid) modify(l, mid, pos, ls, x);
		else modify(mid + 1, r, pos, rs, x);
		t[p].mn = min(t[ls].mn, t[rs].mn);
	}

	inline void add(int l, int r, int ql, int qr, int p, ll x) {
		if(l == ql && r == qr) return pushtag(p, x);
		pushdown(p);
		if(qr <= mid) add(l, mid, ql, qr, ls, x);
		else if(ql > mid) add(mid + 1, r, ql, qr, rs, x);
		else add(l, mid, ql, mid, ls, x), add(mid + 1, r, mid + 1, qr, rs, x);
		t[p].mn = min(t[ls].mn, t[rs].mn);
	}
	
	inline ll query(int l, int r, int ql, int qr, int p) {
//		cerr << l << " " << r << " " << ql << " " << qr << endl;
		if(l == ql && r == qr) return t[p].mn;
		pushdown(p);
		if(qr <= mid) return query(l, mid, ql, qr, ls);
		else if(ql > mid) return query(mid + 1, r, ql, qr, rs);
		else return min(query(l, mid, ql, mid, ls), query(mid + 1, r, mid + 1, qr, rs));
	}
	
	inline ll getmin(int l, int r, int p, int ty) {
		if(l == r) return t[p].mn + ty * r;
		pushdown(p);
		return min(getmin(l, mid, ls, ty), getmin(mid + 1, r, rs, ty));
	}
	#undef ls
	#undef rs
	#undef mid
} T, RT;


int main() {
	n = read(); m = read(); a[1] = read(); a[2] = read(); 
	rep(i, 1, m) a[i + 2] = read();
	T.modify(1, n, a[1], 1, a[1]); RT.modify(1, n, a[1], 1, -a[1]);
	rep(i, 3, m + 2) {
		ll tmp = min(T.query(1, n, a[i], n, 1) - a[i], RT.query(1, n, 1, a[i], 1) + a[i]);
//		cerr << tmp << endl;
		T.add(1, n, 1, n, 1, abs(a[i] - a[i - 1]));
		RT.add(1, n, 1, n, 1, abs(a[i] - a[i - 1]));
		T.modify(1, n, a[i - 1], 1, tmp + a[i - 1]); RT.modify(1, n, a[i - 1], 1, tmp - a[i - 1]);
	}
	cout << T.getmin(1, n, 1, -1) << endl;
	return 0;
}
/*
f[2][1] = 0
f[3][1] = 5 -> ABB
f[3][2] = 2 -> ABA
f[4][1] = 7 -> ABBB
f[4][2] = 4 -> ABAA
f[4][3] = 5 -> ABAB
*/