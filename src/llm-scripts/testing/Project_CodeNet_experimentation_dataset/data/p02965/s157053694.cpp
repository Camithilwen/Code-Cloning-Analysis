#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int put(int a, int b)
{
	int ans = 1;
	while (b) {
		if (b & 1)
			ans = 1LL * ans * a % MOD;
		a = 1LL * a * a % MOD;
		b /= 2;
	}
	return ans;
}

const int NMAX = 2e6;
int fact[NMAX], invfact[NMAX];

void precalc()
{
	fact[0] = 1;
	for (int i = 1; i < NMAX; i++)
		fact[i] = 1LL * i * fact[i - 1] % MOD;
	invfact[NMAX - 1] = put(fact[NMAX - 1], MOD - 2);
	for (int i = NMAX - 1; i >= 1; i--)
		invfact[i - 1] = 1LL * invfact[i] * i % MOD;
}

int comb(int a, int b)
{
	if (a < b || b < 0)
		return 0;
	return 1LL * fact[a] * invfact[b] % MOD * invfact[a - b] % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	precalc();

	int N, M;

	cin >> N >> M;

	int ans = 0;

	for (int nri = 0; nri <= min(N, M); nri++) {
		/// sunt nri impare
		int left = 3 * M - nri;
		if (left % 2 == 1)
			continue;
		left /= 2;
		int modurii = comb(N, nri);
		int modurip = comb(N + left - 1, N - 1);
		ans = (ans + 1LL * modurii * modurip) % MOD;
	}

	for (int toomuch = 2 * M + 1; toomuch <= 3 * M; toomuch++) {
		int moduri = comb(N + 3 * M - toomuch - 2, N - 2);
		ans = (ans - 1LL * moduri * N) % MOD;
	}

	if (ans < 0)
		ans += MOD;

	cout << ans << '\n';


	return 0;
}