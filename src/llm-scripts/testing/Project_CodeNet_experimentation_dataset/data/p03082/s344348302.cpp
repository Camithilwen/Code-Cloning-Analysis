#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using Int = std::int64_t;

constexpr Int MOD = 1e9 + 7;

int main() {
	Int N, X;
	std::cin >> N >> X;

	std::vector<Int> S(N);
	for (auto&& e : S)
		std::cin >> e;

	std::sort(S.begin(), S.end());

	// dp[i][x] := 最初が x のときに i 個目まで見たときの総和
	std::vector<std::vector<Int>> dp(N + 1, std::vector<Int>(X + 1));
	for (Int x = 0; x < X + 1; ++x)
		dp[0][x] = x;

	for (Int i = 1; i < N + 1; ++i) {
		for (Int x = 0; x < X + 1; ++x) {
			// 前に挿入
			dp[i][x] += dp[i - 1][x % S[i - 1]];
			dp[i][x] %= MOD;
			// 後ろに挿入
			dp[i][x] += (i - 1) * dp[i - 1][x];
			dp[i][x] %= MOD;
		}
	}

	std::cout << dp[N][X] << std::endl;
}