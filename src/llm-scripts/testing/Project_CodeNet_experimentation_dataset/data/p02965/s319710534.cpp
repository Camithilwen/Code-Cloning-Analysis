#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = 998244353;

int  N, M;
long long dat[2000009];

long long quickpow(long long b, long long e)
{
	return e ? ((e & 1 ? b : 1)*quickpow((b*b) % MOD, e >> 1)) % MOD : 1;
}

long long combi(int n, int m)
{
	long long retval = dat[n];
	retval = retval * quickpow(dat[n - m], MOD - 2);
	retval = retval % MOD;
	retval = retval * quickpow(dat[m], MOD - 2);
	retval = retval % MOD;
	return retval;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	dat[0] = 1;
	for (int i = 1; i < 2000009; i++) {
		dat[i] = dat[i - 1] * i;
		dat[i] = dat[i] % MOD;
	}
	int lb = min(N, M);
	long long ans = 0, tmp;
	for (int i = 0; i <= lb; i++) {
		if (3 * M - i >= 0 && (3 * M - i) % 2 == 0) {
			tmp = combi((3 * M - i) / 2 + N - 1, N - 1);
			tmp = tmp * combi(N, i);
			tmp = tmp % MOD;
			ans += tmp;
			ans = ans % MOD;
		}
	}
	tmp = combi(M + N - 1, N - 1);
	tmp = tmp + MOD - combi(M + N - 2, N - 2);
	tmp = tmp * N;
	tmp = tmp % MOD;
	ans = ans + MOD - tmp;
	ans = ans % MOD;
	cout << ans << E;
	//system("pause");
	return 0;
}