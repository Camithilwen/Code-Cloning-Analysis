#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1 << 20;
const int MOD = 1e9 + 7;

int trans[ms][2];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[i] ^= a[i-1];
	}
	for(int i = 0; i <= n; i++) {
		//std::cout << a[i] << (i == n ? '\n' : ' ');
	}
	for(int i = 0; i < ms; i++) {
		trans[i][0] = 1;
	}
	int zero = 1;
	int ans = 0;
	int o = a.back() == 0 ? 1 : 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] == 0) {
			if(a.back() == 0 && i != n) {
				o = (o + o) % MOD;
			}
			zero++;
		} else {
			long long val = ((long long) trans[a[i]][1] * zero % MOD + trans[a[i]][0]) % MOD;
			if(a.back() == 0) {
				ans = (ans + val) % MOD;
			} else if(i == n) {
				ans = val;
			}
			trans[a[i]][0] = (trans[a[i]][0] - val * zero % MOD + MOD) % MOD;
			trans[a[i]][1] = (trans[a[i]][1] + val % MOD) % MOD;
		}
	}
	std::cout << (ans + o) % MOD << '\n';
}