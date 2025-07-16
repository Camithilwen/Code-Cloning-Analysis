#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = long long;
using std::cout;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

const int MOD = 998244353;

int main() {
	int n; scanf("%d", &n); std::vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(begin(a), end(a));
	
	int s = 0;
	for(auto v: a) s += v;
	
	auto dp = make_v<i64>(n + 1, s + 1); dp[0][0] = 1;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < s; j++) {
			if(!dp[i][j]) continue;
			(dp[i + 1][j + a[i]] += dp[i][j]) %= MOD;
			(dp[i + 1][j] += dp[i][j]) %= MOD;
			(dp[i + 1][j] += dp[i][j]) %= MOD;
		}
	}
	
	i64 ans = 1;
	for(int i = 0; i < n; i++) (ans *= 3LL) %= MOD;
	
	i64 sub = 0;
	for(int i = (s + 1) / 2; i <= s; i++) (sub += dp[n][i]) %= MOD;
	
	if(!(s & 1)) {
		auto dp2 = make_v<i64>(n + 1, s + 1); dp2[0][0] = 1;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < s; j++) {
				if(!dp2[i][j]) continue;
				(dp2[i + 1][j + a[i]] += dp2[i][j]) %= MOD;
				(dp2[i + 1][j] += dp2[i][j]) %= MOD;
			}
		}
		
		(sub -= dp2[n][s / 2] - MOD) %= MOD;
	}
	printf("%lld\n", (ans - 3 * sub % MOD + MOD) % MOD);
	return 0;
}
