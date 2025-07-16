#include <bits/stdc++.h>

#define F(i, a, b) for (ll i = a; i <= b; i ++)
#define G(i, a, b) for (ll i = a; i >= b; i --)
#define out4(x, y, z, w) { if (debug) printf(#x" = "),W(x),printf(" "#y" = "),W(y),printf(" "#z" = "),W(z),printf(" "#w" = "),W(w),putc('\n'); }
#define out3(x, y, z) { if (debug) printf(#x" = "), W(x), printf(" "#y" = "), W(y), printf(" "#z" = "), W(z), putc('\n'); }
#define out2(x, y) { if (debug) printf(#x" = "), W(x), printf(" "#y" = "), W(y), putc('\n'); }
#define out1(x) { if (debug) printf(#x" = "), W(x), putc('\n'); }
#define outline(x) { if (debug) puts("-------------------------------------------"#x"----------------------------------------"); }
#define outarr(a, L, R) { if (debug) { printf(#a"[%d..%d] = ", L, R); F(i, L, R) W(a[i]), putc(' '); putc('\n'); } }
#define Assert(x) { if ((debug) && (!(x))) { puts("Wrong Answer"); exit(0); } }
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define mem(a, b) memset(a, b, sizeof a)
#define mec(a, b) memcpy(a, b, sizeof a)
#define mx(a, b) ((a) = max(a, b))
#define mn(a, b) ((a) = min(a, b))
#define lowbit(x) ((x) & (-(x)))
#define abs(x) ((max(x, - (x))))
#define get getchar()
#define pb push_back
#define putc putchar
#define inf 2e9

template <typename Int>
void R(Int &x) {
	char c = get; x = 0; Int t = 1;
	for (; !isdigit(c); c = get) t = (c == '-' ? - 1 : t);
	for (; isdigit(c); x = (x << 3) + (x << 1) + c - '0', c = get); x *= t;
}
template <typename Int>
void W(Int x) {
	if (x < 0) { putc('-'); x = - x ; }
	if (x > 9) W(x / 10); putc(x % 10 + '0');
}

#define debug (0)

using namespace std;

#define ll long long
const ll N = 1e5 + 10;
ll n, s, x[N], p[N];
struct node { ll s, v; };

node Dfs(ll l, ll r) {
	out2(l, r);
	outarr(p, 1, n);
	if (s <= x[l]) return {x[r], x[r] - s};
	if (s >= x[r]) return {x[l], s - x[l]};
	if (p[l] < p[r]) {
		p[r] += p[l];
		node a = Dfs(l + 1, r);
		return {x[l], a.v + a.s - x[l]};
	}
	else {
		p[l] += p[r];
		node a = Dfs(l, r - 1);
		return {x[r], a.v + x[r] - a.s};
	}
}

int main() {
//	freopen("data.in","r",stdin);

	R(n), R(s);
	F(i, 1, n) R(x[i]), R(p[i]);

	W(Dfs(1, n).v);
}