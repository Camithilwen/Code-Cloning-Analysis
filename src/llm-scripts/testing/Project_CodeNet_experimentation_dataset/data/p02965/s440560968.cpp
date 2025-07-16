#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int fac[2000005], ifac[2000005];

void gen_fac()
{
	fac[0] = 1;
	rep1(i, 2000000) fac[i] = 1LL * fac[i - 1] * i % MOD;
	ifac[1] = 1;
	for(int i = 2; i <= 2000000; i ++) ifac[i] = MOD - 1LL * ifac[MOD % i] * (MOD / i) % MOD;
	ifac[0] = 1;
	rep1(i, 2000000) ifac[i] = 1LL * ifac[i - 1] * ifac[i] % MOD;
}

int comb(int n, int m)
{
	if(n < m) return 0;
	return 1LL * fac[n] * ifac[n - m] % MOD * ifac[m] % MOD;
}

int solve(int n, int m, int k)
{
	int tot = comb((3 * m - k) / 2 + n - 1, n - 1);
	tot = (tot - 1LL * k * comb((m - k) / 2 + n - 1, n - 1) % MOD + MOD) % MOD;
	tot = (tot - 1LL * (n - k) * comb((m - k - 2) / 2 + n - 1, n - 1) % MOD + MOD) % MOD;
	return tot;
}

int main()
{
	gen_fac();
	int n, m;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for(int i = 0; i <= m; i ++)
	if(!(m - i & 1)) ans = (ans + 1LL * comb(n, i) * solve(n, m, i)) % MOD;
	printf("%d\n", ans);
	return 0;
}