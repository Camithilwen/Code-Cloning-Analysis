#include<iostream>

int cnt[100005];
const long long mod = 998244353;
int max_val = 0;
long long ans = 1;

long long mpow(int a, int b) {
	if (!a) return 0LL;
	if (!b) return 1LL;
	return b%2 ? (long long)a * mpow(a, b-1) % mod : mpow((long long)a*a%mod, b/2);
}

int main(void) {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int d;
		std::cin >> d;
		if (d > max_val) max_val = d;
		if (!i && d || i && !d) {
			std::cout << 0 << '\n';
			return 0;
		}
		cnt[d]++;
	}

	for (int i = 2; i <= max_val; i++) {
		ans = (ans * mpow(cnt[i-1], cnt[i])) % mod;
	}

	std::cout << ans << '\n';
	return 0;
}
