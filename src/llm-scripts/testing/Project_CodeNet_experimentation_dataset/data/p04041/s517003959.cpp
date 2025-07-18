#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int N = (1 << 16) + 7;
int dp[2][N];
int n, m, W;

void read() {
	int x, y, z;
	scanf("%d%d%d%d", &n, &x, &y, &z);
	m = x + y + z - 1;
	W = (1 << (x + y + z - 1)) ^ (1 << (y + z - 1)) ^ (1 << (z - 1));
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	dp[0][0] = 1;
	while(n--) {
		for (int i = 0; i <= (1 << m); i++)
			dp[1][i] = 0;
		dp[1][1 << m] = add(dp[1][1 << m], mult(dp[0][1 << m], 10));
		for (int mask = 0; mask < (1 << m); mask++) {
			for (int x = 1; x <= 10; x++) {
				int nmask = (mask << x) ^ (1 << (x - 1));
				if ((nmask & W) == W)
					nmask = 1 << m;
				else
					nmask &= (1 << m) - 1;
				dp[1][nmask] = add(dp[1][nmask], dp[0][mask]);
			}
		}
		for (int i = 0; i <= (1 << m); i++)
			dp[0][i] = dp[1][i];
	}
	printf("%d\n", dp[0][1 << m]);

	return 0;
}
