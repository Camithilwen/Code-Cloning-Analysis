#include <bits/stdc++.h>
using namespace std::literals::string_literals;
using i64 = std::int_fast64_t;
using std::cout;
using std::cerr;
using std::endl;
using std::cin;

template<typename T>
std::vector<T> make_v(size_t a){return std::vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return std::vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

i64 pow(i64 x, i64 n, i64 m) {
	i64 ret = 1;
	while(n) {
		if(n & 1) (ret *= x) %= m;
		(x *= x) %= m;
		n >>= 1;
	}
	return ret;
}

i64 inv(i64 n, i64 m) {
	return pow(n, m - 2, m);
}

int main() {
	i64 n, m; scanf("%lld%lld", &n, &m);

	i64 N = 1;
	for(i64 i = 1; i <= 3 * n; i++) N = N * i % m;

	std::vector<int> tan(3 * n + 1);
	for(i64 i = 0; i < tan.size(); i++) tan[i] = inv(i, m);

	int offset = 3 * n;
	auto dp = make_v<int>(3 * n + 1, 6 * n + 1); dp[0][offset] = N;
	for(int i = 0; i < 3 * n; i++) {
		for(int j = 0; j < 6 * n; j++) {
			i64 from = dp[i][j];
			if(!from) continue;
			
			if(i + 1 <= 3 * n) (dp[i + 1][j + 1] += from * tan[i + 1] % m) %= m;
			if(i + 2 <= 3 * n)(dp[i + 2][j - 1] += from * tan[i + 2] % m) %= m;
			if(i + 3 <= 3 * n)(dp[i + 3][  j  ] += from * tan[i + 3] % m) %= m;
		}
	}

	i64 ans = 0;
	for(int i = offset; i < 6 * n + 1; i++) (ans += dp[3 * n][i]) %= m;
	printf("%lld\n", ans);
	return 0;
}
