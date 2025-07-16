#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
#define INF (1 << 30)
#define MOD 1000000007

template<class T> inline void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> inline void chmin(T& a, T b) { if (a > b) a = b; }

class Combination
{
	vector<ll> fact, finv;
public:Combination(int n) {
	fact.resize(n + 1, 1);
	finv.resize(n + 1, 1);
	vector<ll> inv(n + 1, 1);
	for (int i = 2; i <= n; ++i) {
		fact[i] = fact[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}
public:ll comb(int n, int k) {
	return fact[n] * (finv[n - k] * finv[k] % MOD) % MOD;
}
};
map<int, int> factorize(int x)
{
	map<int, int> m;
	for (int i = 2; i * i <= x; ++i) {
		while (x % i == 0) {
			x = x / i;
			++m[i];
		}
	}
	if (x != 1) {
		++m[x];
	}
	return m;
}
int main()
{
	int N, M; cin >> N >> M;
	auto m = factorize(M);
	auto C = Combination(N + 100);
	ll ans = 1;
	for (auto i : m) {
		ans *= C.comb(N + i.second - 1, i.second);
		ans = ans % MOD;
	}
	cout << ans << endl;
	return 0;
}
