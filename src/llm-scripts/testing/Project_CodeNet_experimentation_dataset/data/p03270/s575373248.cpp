#define  REP(i, s, e) for (int i = s; i <= e; i++)
#define DREP(i, s, e) for (int i = s; i >= e; i--)
#define DEBUG fprintf(stderr, "Passing [%s] in Line %d\n", __FUNCTION__, __LINE__)

#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 4000 + 10, MOD = 998244353;

int n, k, tot[maxn];
long long fac[maxn], Inv[maxn];
inline int C(int n, int m) {return fac[n] * Inv[m] % MOD * Inv[n-m] % MOD;}

int power_pow(long long base, int b)
{
	long long ans(1);
	while (b)
	{
		if (b & 1) (ans *= base) %= MOD;
		(base *= base) %= MOD;
		b >>= 1;
	}
	return ans;
}
#define inv(x) power_pow(x, MOD - 2)
inline void init()
{
	fac[0] = 1;
	REP(i, 1, 4000) fac[i] = fac[i-1] * i % MOD;
	Inv[4000] = inv(fac[4000]);
	DREP(i, 3999, 0) Inv[i] = Inv[i+1] * (i+1) % MOD;
}

int main()
{
#ifdef CraZYali
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	init();
	cin >> k >> n;
	REP(i, 1, k) tot[i+1]++, tot[i+k+1]--;
	REP(i, 1, k + k) tot[i] += tot[i-1];
	REP(i, 2, k + k)
    {
		int cnt = tot[i] + 1 >> 1, ans(0);
		const int lim = min(cnt, n >> 1);
		REP(j, 0, lim)
			(ans += (j & 1 ? -1ll : 1ll) * C(cnt, j) * C(n-j-j+k-1, k-1) % MOD) %= MOD;
        printf("%d\n", (ans + MOD) % MOD);
    }
    return 0;
}
