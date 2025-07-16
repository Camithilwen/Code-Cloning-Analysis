#include <stdio.h>

#include <iostream>
#include <vector>
#include <array>

constexpr int64_t MOD = 1'000'000'007;
constexpr int64_t help = 1;

int main() {
	int64_t n;

	std::cin >> n;

	std::array<uint64_t, 62> bits{};
	for (int64_t i = 0; i < n; i++) {
		int64_t d;
		std::cin >> d;
		for (int64_t b = 0; b < 62; b++) {
			bits[b] += !!(d & (help << b));
		}
	}

	int64_t ans = 0;

	for (int64_t b = 0; b < 62; b++) {
		int64_t p = (help << b) % MOD;
		ans += (bits[b]*(n-bits[b]) % MOD) * p;
		ans %= MOD;
	}

	std::cout << ans;
  return 0;
}
