#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
const int N_MAX = 100000;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}

long long inverse[N_MAX+1+64];
long long factorial[N_MAX+1+64];
long long factorial_inverse[N_MAX+1+64];

void calc(int n) {
	inverse[1] = 1;
	factorial[0] = factorial[1] = 1;
	factorial_inverse[0] = factorial_inverse[1] = 1;
	for (int i = 2; i <= n; i++) {
		inverse[i] = MOD - inverse[MOD%i] * (MOD/i) % MOD;
		factorial[i] = i * factorial[i-1] % MOD;
		factorial_inverse[i] = inverse[i] * factorial_inverse[i-1] % MOD;
	}
}

long long comb(long long n, long long k) {
	return factorial[n] * (factorial_inverse[k] * factorial_inverse[n-k] % MOD) % MOD;
}

long long rep_comb(long long n, long long k) {
	return comb(n + k - 1, k);
}

vector<pair<long long, int>> prime_factorization(long long n) {
	vector<pair<long long, int>> v;
	for (long long i = 2; i * i <= n; ++i) {
		int e = 0;
		while (n % i == 0) {
			++e;
			n /= i;
		}
		if (e != 0) v.emplace_back(i, e);
	}
	if (n != 1) v.emplace_back(n, 1);
	return v;
}

int main() {
	calc(N_MAX+65);
	long long n, m;
	cin >> n >> m;
	long long ans = 1;
	auto v = prime_factorization(m);
	for (auto el : v) {
		long long e = el.second;
		ans = mod(ans * rep_comb(n, e));
	}
	cout << ans << endl;
	return 0;
}