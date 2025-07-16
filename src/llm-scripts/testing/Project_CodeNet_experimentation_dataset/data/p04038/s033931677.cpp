#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;

#define ge (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define ri read_int()
#define rl read_ll()
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)

template<typename T>
inline void read(T &x) {
	char ch, t = 0; x = 0;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = ge;
	x = t ? -x : x;
}
inline int read_int() { int x; return read(x), x; }
inline ll read_ll() { ll x; return read(x), x; }

template<typename T>
inline void chkmin(T&a, T b) { a = a < b ? a : b; }

const int MAXN = 2010;
const int mod = 1e9 + 7;

inline int ksm(int x, int k = mod - 2) {
	int s = 1;
	while(k) {
		if(k & 1) s = 1LL * s * x % mod;
		x = 1LL * x * x % mod, k >>= 1;
	} return s;
}

int fac[MAXN * MAXN];
int ifac[MAXN * MAXN];
int f[MAXN][MAXN];

inline void init(int n) {
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
	ifac[n] = ksm(fac[n]);
	for(int i = n; i >= 1; i--) ifac[i - 1] = 1LL * ifac[i] * i % mod;
}

inline int C(int n, int m) {
	return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int main() {
#ifdef LOCAL
	FILE("");
#endif

	int n = ri, k = ri, N = n * k;
	init(N);

	if(k == 1) return puts("1"), 0;

	for(int i = 0; i <= n; i++) f[i][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= i; j++)
			if(j) f[i][j] = (f[i - 1][j] + 1LL * f[i][j - 1] * C(N - i - (j - 1) * (k - 1) - 1, k - 2)) % mod;
			else f[i][j] = f[i - 1][j];

	printf("%lld\n", 1LL * f[n][n] * fac[n] % mod);
	return 0;
}