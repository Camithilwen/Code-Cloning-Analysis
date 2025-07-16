//Author:xht37
#include <bits/stdc++.h>

#define ui unsigned int
#define ll long long
#define ul unsigned ll
#define ld long double

#define pi pair <int, int>
#define fi first
#define se second
#define mp make_pair

#define ls (p << 1)
#define rs (ls | 1)
#define md ((t[p].l + t[p].r) >> 1)

#define vi vector <int>
#define pb push_back
#define pq priority_queue

#define dbg(x) cerr << #x" = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)

#define fl(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)

using namespace std;

namespace io {
	const int SI = 1 << 21 | 1;
	char IB[SI], *IS, *IT, OB[SI], *OS = OB, *OT = OS + SI - 1, c, ch[100];
	int f, t;
	#define gc() (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin), IS == IT ? EOF : *IS++) : *IS++)
	inline void flush() {
		fwrite(OB, 1, OS - OB, stdout), OS = OB;
	}
	inline void pc(char x) {
		*OS++ = x;
		if (OS == OT) flush();
	}

	template <class I>
	inline void rd(I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15), c = gc());
		x *= f;
	}
	template <class I>
	inline void rd(I &x, I &y) {
		rd(x), rd(y);
	}
	template <class I>
	inline void rd(I &x, I &y, I &z) {
		rd(x), rd(y), rd(z);
	}
	template <class I>
	inline void rda(I *a, int n) {
		for (int i = 1; i <= n; i++) rd(a[i]);
	}
	inline void rdc(char &c) {
		for (c = gc(); c < 33 || c > 126; c = gc());
	}
	inline void rds(char *s, int &n) {
		for (c = gc(); c < 33 || c > 126; c = gc());
		for (n = 0; c >= 33 && c <= 126; s[++n] = c, c = gc());
		s[n+1] = '\0';
	}
	inline void rds(string &s) {
		for (c = gc(); c < 33 || c > 126; c = gc());
		for (s.clear(); c >= 33 && c <= 126; s.pb(c), c = gc());
	}

	template <class I>
	inline void print(I x, char k = '\n') {
		if (!x) pc('0');
		if (x < 0) pc('-'), x = -x;
		while (x) ch[++t] = x % 10 + '0', x /= 10;
		while (t) pc(ch[t--]);
		pc(k);
	}
	template <class I>
	inline void print(I x, I y) {
		print(x, ' '), print(y);
	}
	template <class I>
	inline void print(I x, I y, I z) {
		print(x, ' '), print(y, ' '), print(z);
	}
	template <class I>
	inline void printa(I *a, int n) {
		for (int i = 1; i <= n; i++) print(a[i], " \n"[i==n]);
	}
	inline void printc(char c) {
		pc(c);
	}
	inline void prints(char *s, int n) {
		for (int i = 1; i <= n; i++) pc(s[i]);
		pc('\n');
	}
	inline void prints(string s) {
		int n = s.length();
		while (t < n) pc(s[t++]);
		pc('\n'), t = 0;
	}
	struct Flush {
		~Flush() {
			flush();
		}
	} flusher;
}
using io::rd;
using io::rda;
using io::rdc;
using io::rds;
using io::print;
using io::printa;
using io::printc;
using io::prints;

const int N = 1e5 + 7;
int n, x, p[N];
ll b[N], l[N], r[N], s[N], sum;

inline ll calc(int x, ll t) {
	return t <= b[x] ? t * l[x] : b[x] * l[x] + (t - b[x]) * r[x];
}

inline ll pd(ll t) {
	int w = t % x ? t % x : x, c = (t - w) / x;
	ll sum = 0, ret = 0;
	for (int i = 1; i <= c; i++) sum += s[p[i]];
	for (int i = c + 1; i <= n; i++)
		ret = max(ret, sum + calc(p[i], w));
	sum += s[p[c+1]];
	for (int i = 1; i <= c; i++)
		ret = max(ret, sum - s[p[i]] + calc(p[i], w));
	return ret;
}

int main() {
	rd(n, x);
	for (int i = 1; i <= n; i++)
		rd(b[i], l[i], r[i]), p[i] = i,
		s[i] = b[i] * l[i] + (x - b[i]) * r[i], sum += b[i] * l[i];
	sort(p + 1, p + n + 1, [&](int i, int j) { return s[i] > s[j]; });
	if (!sum) return print(0), 0;
	ll l = 1, r = 1ll * n * x;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (pd(mid) >= sum) r = mid;
		else l = mid + 1;
	}
	print(l);
	return 0;
}