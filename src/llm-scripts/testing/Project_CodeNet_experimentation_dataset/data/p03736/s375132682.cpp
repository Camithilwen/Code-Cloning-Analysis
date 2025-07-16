#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define rg register
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const LL INF = 0x3f3f3f3f3f3f3f3f;

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

template <typename T> inline void cmin(T &x, T y) {
	if (x > y) x = y;
}

template <typename T> inline void cmax(T &x, T y) {
	if (x < y) x = y;
}

int n, q, A, B, p[MAXN];
LL csum[MAXN], dp[MAXN];

struct BIT {
	LL tr[MAXN];
	BIT() {
		mset(tr, 0x3f);
	}
	inline int lowbit(int x) {
		return x & (-x);
	}
	inline void update(int x, LL val) {
		for (int i=x;i<=n;i+=lowbit(i)) {
			cmin(tr[i], val);
		}
	}
	inline LL query(int x) {
		LL ret = INF;
		for (int i=x;i;i-=lowbit(i)) {
			cmin(ret, tr[i]);
		}
		return ret;
	}
}t1, t2;

void init() {
	read(n); read(q);
	read(A); read(B);
	for (int i=1;i<=q;++i) {
		read(p[i]);
	}
	for (int i=2;i<=q;++i) {
		csum[i] = csum[i-1] + abs(p[i]-p[i-1]);
	}
}

void solve() {
	dp[0] = min(abs(A-p[1]), abs(B-p[1]));
	t1.update(A, abs(B-p[1]) - A);
	t2.update(n-A+1, abs(B-p[1]) + A);
	t1.update(B, abs(A-p[1]) - B);
	t2.update(n-B+1, abs(A-p[1]) + B);
	for (int i=1;i<q;++i) {
		dp[i] = min( t1.query(p[i+1]) + csum[i] + p[i+1], 
					 t2.query(n-p[i+1]+1) + csum[i] - p[i+1] );
		t1.update(p[i], dp[i] - csum[i+1] - p[i]);
		t2.update(n-p[i]+1, dp[i] - csum[i+1] + p[i]);
	}
	LL ans = INF;
	for (int i=0;i<q;++i) {
		cmin(ans, dp[i] + csum[q] - csum[i+1]);
	}
	printf("%lld\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}
