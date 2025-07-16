#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

const LL mod = 1000000007;
LL N, X;
std::vector<LL>S;
std::vector<std::vector<LL>>memo;

LL dp(LL i, LL j)
{
	if (j == N) return i;
	if (memo[i][j] != -1) return memo[i][j];
	LL res1 = dp(i%S[j], j + 1);
	LL res2 = (dp(i, j + 1)*(N - j - 1)) % mod;
	return memo[i][j] = (res1 + res2) % mod;
}

int main()
{
	in >> N >> X;
	S.resize(N);
	rep(i, N) in >> S[i];

	memo.resize(X + 1, std::vector<LL>(N + 1, -1));
	std::sort(S.begin(), S.end(), std::greater<LL>());
	out << dp(X, 0) << std::endl;
}
