#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm> 
#include <cmath>

using namespace std;

typedef long long LL;

const int MOD = 1000000007;
const int MAXN = 2 * 100005;

LL H, W;
LL A, B;
LL fact[MAXN];

// Exponentiation by squaring
LL expsq(LL x, LL p) {
	LL res = 1;
	while (p > 0) {
		if (p & 1) {
			res = (res * x) % MOD;
		}
		x = (x * x) % MOD;
		p /= 2;
	}
	return res;
}

// Extended Euler's algorithm
LL modinv(LL x) {
	return expsq(x, MOD - 2);
}

LL C(LL n, LL k) {
	return (fact[n] * modinv(fact[n - k] * fact[k] % MOD)) % MOD;
}

int main() {
	cin >> H >> W >> A >> B;
	fact[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}

	LL ans = 0;
	for (LL i = B; i <= W - 1; i++) {
		LL res = C(H - A - 1 + i, i);
		LL end = C(W - i - 1 + A - 1, A - 1);
		res *= end;
		res %= MOD;

		ans += res;
		ans %= MOD;
	}

	cout << ans << endl;
}