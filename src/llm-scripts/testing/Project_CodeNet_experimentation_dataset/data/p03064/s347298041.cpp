#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <array>
#include <queue>
#include <stack>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <type_traits>

#define MOD 998244353

int main()
{
	long dp0[300*300+1]={}, dp1[300*300+1]={};
	long sub0[300*300+1]={}, sub1[300*300+1]={};

	long N;
	std::vector<int> A;
	std::cin >> N;
	A.resize(N);
	for (auto& a : A) {
		std::cin >> a;
	}
	long sum = 0;
	for (auto a : A) {
		sum += a;
	}

	dp0[0] = 1;
	sub0[0] = 1;

	long* prevdp = dp0;
	long* dp = dp1;
	long* prevsub = sub0;
	long* sub = sub1;

	for (auto a : A) {
		for (int i = 0; i < a; ++i) {
			dp[i] = prevdp[i]*2 % MOD;
			sub[i] = prevsub[i];
		}
		for (int i = a; i <= 300*300; ++i) {
			dp[i] = (prevdp[i-a] + prevdp[i]*2) % MOD;
			sub[i] = (prevsub[i-a] + prevsub[i]) % MOD;
		}
		std::swap(dp, prevdp);
		std::swap(sub, prevsub);
	}

	long ret = 1;
	for (long i = 0; i < N ; ++i)
		ret = (ret * 3) % MOD;

	for (long i = (sum+1)/2; i <= 300*300; ++i) {
		ret = (ret + (MOD - prevdp[i])*3) % MOD;
	}
	if (sum%2 == 0) {
		ret = (ret + prevsub[sum/2]*3) % MOD;
	}
	std::cout << ret << "\n";
}
