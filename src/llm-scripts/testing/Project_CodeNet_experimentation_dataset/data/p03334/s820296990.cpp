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

const int N = 607;
int n;
struct G {
	int d, c[N][N];
	vector<pi> p;
	inline bool pd(int x, int y) {
		return x >= 0 && x < n * 2 && y >= 0 && y < n * 2 && !~c[x][y];
	}
	void dfs(int x, int y, int z) {
		c[x][y] = z;
		for (pi o : p) {
			int X = x + o.fi, Y = y + o.se;
			if (pd(X, Y)) dfs(X, Y, z ^ 1);
		}
	}
	inline void main() {
		rd(d);
		for (int i = 0; i < n * 2; i++)
			for (int j = 0; j < n * 2; j++)
				c[i][j] = -1;
		for (int i = 1 - n * 2; i < n * 2; i++)
			for (int j = 1 - n * 2; j < n * 2; j++)
				if (i * i + j * j == d) p.pb(mp(i, j));
		for (int i = 0; i < n * 2; i++)
			for (int j = 0; j < n * 2; j++)
				if (pd(i, j)) dfs(i, j, 0);
	}
} g[2];
vector<pi> p[4];

int main() {
	rd(n), g[0].main(), g[1].main();
	for (int i = 0; i < n * 2; i++)
		for (int j = 0; j < n * 2; j++)
			p[g[1].c[i][j]*2+g[0].c[i][j]].pb(mp(i, j));
	int o = 0;
	for (int i = 1; i < 4; i++)
		if (p[i].size() > p[o].size()) o = i;
	while ((int)p[o].size() > n * n) p[o].pop_back();
	for (pi x : p[o]) print(x.fi, x.se);
	return 0;
}