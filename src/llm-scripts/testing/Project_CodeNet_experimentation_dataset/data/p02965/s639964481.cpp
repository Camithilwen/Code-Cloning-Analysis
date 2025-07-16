#include <iostream>
#include <algorithm>
#define int long long
using namespace std;

const int MAX = 2600000;
int mod = 998244353;
int n, m;
int fact[MAX];
int inv[MAX];
int factInv[MAX];

void initFact() {
	int i;
	
	fact[0] = fact[1] = 1;
	factInv[0] = factInv[1] = 1;
	inv[1] = 1;
	for (i = 2; i <= 3 * m + n; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
		inv[i] = mod - inv[mod % i] * (mod / i) % mod;
		factInv[i] = factInv[i - 1] * inv[i] % mod;
	}
}

int comb(int n, int k) {
	if (k > n) return 0;
	return fact[n] * factInv[n - k] % mod * factInv[k] % mod;
}

signed main() {
	cin >> n >> m;
	initFact();
	
	int x;
	int ng = 0;
	for (x = 2 * m + 1; x <= 3 * m; x++) {
		int res = n * comb(3 * m - x + n - 2, n - 2) % mod;
		ng += res;
		ng %= mod;
	}
	
	//奇数がx個
	for (x = m + 1; x <= n; x++) {
		if (x > 3 * m) break;
		if ((3 * m - x) % 2 != 0) continue;
		int res = comb((3 * m - x) / 2 + n - 1, n - 1) * comb(n, x) % mod;
		ng += res;
		ng %= mod;
	}
	
	int all = comb(3 * m + n - 1, n - 1);
	int ans = (all - ng + mod) % mod;
	
	cout << ans << endl;
	return 0;
}
