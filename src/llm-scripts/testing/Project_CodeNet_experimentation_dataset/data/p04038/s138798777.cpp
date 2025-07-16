#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a), i##_end_ = (b); i <= i##_end_; ++i)
#define drep(i, a, b) for(int i = (a), i##_end_ = (b); i >= i##_end_; --i)
#define clar(a, b) memset((a), (b), sizeof(a))
#define debug(...) fprintf(stderr, __VA_ARGS__)
typedef long long LL;
typedef long double LD;
const int BUF_SIZE = (int)1e6 + 10;
struct fastIO {
	char buf[BUF_SIZE], buf1[BUF_SIZE];
	int cur, cur1; FILE *in, *out;
	fastIO() { cur = BUF_SIZE, in = stdin, out = stdout; cur1 = 0; }
	inline char getchar() { if(cur == BUF_SIZE) fread(buf, BUF_SIZE, 1, in), cur = 0; return *(buf + (cur++)); }
	inline void putchar(char ch) { *(buf1 + (cur1++)) = ch; if (cur1 == BUF_SIZE) fwrite(buf1, BUF_SIZE, 1, out), cur1 = 0; } inline int flush() { if (cur1 > 0) fwrite(buf1, cur1, 1, out); return cur1 = 0; }
}IO;
#define getchar IO.getchar
#define putchar IO.putchar
LL read() {
	char ch = getchar();
	LL x = 0, flag = 1;
	for (;!isdigit(ch); ch = getchar()) if (ch == '-') flag *= -1;
	for (;isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
	return x * flag;
}
void write(LL x) {
	if (x < 0) putchar('-'), x = -x;
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int Maxn = 4009, Mod = 1e9 + 7;
int n, k, fac[Maxn * Maxn / 4], invFac[Maxn * Maxn / 4];

LL fpm(LL base, LL tims) {
	LL r = 1;
	while (tims) {
		if (tims & 1) r = r * 1ll * base % Mod;
		base = base * 1ll * base % Mod;
		tims >>= 1;
	}
	return r;
}

void init() {
	n = read(), k = read();
	fac[0] = 1;
	rep (i, 1, n * k) fac[i] = fac[i - 1] * 1ll * i % Mod;
	invFac[n * k] = fpm(fac[n * k], Mod - 2);
	drep (i, n * k - 1, 0) invFac[i] = invFac[i + 1] * (i + 1ll) % Mod;
}

LL C(int n, int m) {
	if (n < m) return 0;
	return 1ll * fac[n] * invFac[m] % Mod * invFac[n - m] % Mod;
}

LL dp[Maxn][Maxn];
void solve() {
	if (k == 1) {
		puts("1");
		return ;
	}
	dp[0][0] = 1;
	rep (i, 0, n)
		rep (j, 0, i) {
			(dp[i + 1][j] += dp[i][j]) %= Mod;
			(dp[i][j + 1] += dp[i][j] * 1ll * C(n * k - i - j * (k - 1) - 1, k - 2) % Mod) %= Mod;
		}
	cout << 1ll * dp[n][n] * fac[n] % Mod << endl;
}

int main() {
//	freopen("bosky.in", "r", stdin);
//	freopen("bosky.out", "w", stdout);

	init();
	solve();

#ifdef Qrsikno
	debug("\nRunning time: %.3lf(s)\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
	return IO.flush();
}

