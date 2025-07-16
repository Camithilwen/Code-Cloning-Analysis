#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
const int MAX = 100000;
int above[MAX + 2];
ll dp[MAX + 1];
const int MAXN = 205;
ll fac[MAXN], invfac[MAXN];
ll inv[MAXN];
const ll MOD = 1e9 + 7;
int binom[MAXN][MAXN];
ll modex(ll a, ll p, ll m = MOD) {
	if (!p) return 1;
	if (p & 1) return a * modex(a, p - 1, m) % m;
	ll v = modex(a, p >> 1, m);
	return v * v % m;
}
int main() {
	fac[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		fac[i] = fac[i - 1] * i % MOD;
	invfac[MAXN - 1] = modex(fac[MAXN - 1], MOD - 2);
	for (int i = MAXN - 2; i >= 0; --i)
		invfac[i] = invfac[i + 1] * (i + 1) % MOD;
	for (int i = 1; i < MAXN; ++i)
		inv[i] = invfac[i] * fac[i - 1] % MOD;
	for (int i = 0; i < MAXN; ++i)
		for (int j = 0; j <= i; ++j)
			if (!j || j == i) binom[i][j] = 1;
			else binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % MOD;
	int n, X;
	scanf("%d%d", &n, &X);
	vector<int> s(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &s[i]);
		above[s[i] - 1] = 1;
	}
	sort(s.begin(), s.end());
	for (int i = MAX; i >= 0; --i) above[i] += above[i + 1];
	for (int i = 0; i <= X; ++i) {
		for (int k = 0; k < n; ++k) {
			if (s[k] > i) break;
			int v = i % s[k];
			dp[i] += dp[v] * binom[n - above[i] - 1][n - above[v]] % MOD * fac[above[v] - above[i] - 1] % MOD;
			dp[i] %= MOD;
		}
		if (s[0] > i) dp[i] = i;
	}
	printf("%lld\n", dp[X] * binom[n][above[X]] % MOD * fac[above[X]] % MOD);
}
