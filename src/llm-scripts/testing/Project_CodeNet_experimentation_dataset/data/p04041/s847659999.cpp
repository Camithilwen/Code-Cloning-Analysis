// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2")

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <chrono>
#include <vector>
#include <map>
#include <random>
#include <set>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <stdio.h>
#include <queue>
#include <bitset>
#include <cstdlib>
#include <deque>
#include <cassert>
#include <stack>
using namespace std;

#define mp make_pair
#define f first
#define se second
#define pb push_back
#define ppb pop_back
#define ll long long
#define ull unsigned long long
#define cntbit(x) __builtin_popcount(x)
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define ld long double
#define pll pair<long long, long long>

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void setin(string s) {
	freopen(s.c_str(), "r", stdin);
}

inline void setout(string s) {
	freopen(s.c_str(), "w", stdout);
}

template <typename T> inline T range(T l, T r) {
	return uniform_int_distribution <T>(l, r)(rng);
}

template <typename T> void Min(T &a, T b) {
    a = min(a, b);
}
 
template <typename T> void Max(T &a, T b) {
    a = max(a, b);
}

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 45;
const int K = 17;
int n, x, y, z;
bool good[1 << K];

int pw[K];

int dp[N][1 << K];

int ans;

inline int add(int a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
	return a;
}

inline int mt(int a, int b) {
	return 1ll * a * b % mod;
}

inline void add_t(int &a, int b) {
	a = add(a, b);
}

inline void precalc() {
	for(int mask = 0; mask < (1 << K); ++mask) {
		good[mask] = true;
		string s = "";
		for(int j = 0; j < K; ++j) {
			if(1 << j & mask)
				s += '1';
			else
				s += '0';
		}
		while(s.back() == '0')
			s.ppb();
		// reverse(s.begin(), s.end());
		// if(mask == (1 << 4) + (1 << 11) + (1 << 16))
		// 	cout << s << endl;
		int cur = 0;
		// if(mask % 1000 == 0)
		// 	cout << s << endl;
		vector <int> is = {};
		for(int i = 0; i < s.size(); ++i) {
			int j = i;
			while(j < s.size() && s[j] != '1')
				++j;
			// if(s[j] != '0')
			is.pb(j - i + 1);
			// if(mask % 1000 == 0)
			// 	cout << j - i + 1 << ' ';
			// if(mask == (1 << 4) + (1 << 11) + (1 << 16))
			// 	cout << j - i + 1 << ' ';
			i = j;
		}
		reverse(is.begin(), is.end());
		for(int i = 1; i < is.size(); ++i)
			is[i] += is[i-1];
		for(int i = 0; i < is.size(); ++i) {
			for(int j = i + 1; j < is.size(); ++j) {
				for(int k = j + 1; k < is.size(); ++k) {
					int sum1 = is[j-1] - (i == 0 ? 0 : is[i-1]);
					int sum2 = is[k-1] - is[j-1];
					int sum3 = is.back() - is[k-1];
					if(sum1 == x && sum2 == y && sum3 == z) {
						good[mask] = false;
						break;
					}
				}
			}
		}
		// if(mask % 1000 == 0)
		// 	cout << endl;
		// if(mask == (1 << 4) + (1 << 11) + (1 << 16))
		// 	cout << endl;
	}
}

main() {
	for(int i = 1; i < K; ++i)
		pw[i] = 1 << (i - 1);
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	// setin("input.txt");
	cin >> n >> x >> y >> z;
	precalc();
	for(int i = 1; i <= 10; ++i)
		if(good[pw[i]])
			dp[1][pw[i]] = 1;
	for(int i = 2; i <= n; ++i) {
		for(int mask = 0; mask < (1 << K); ++mask) {
			for(int j = 1; j <= 10; ++j) {
				int new_mask = ((1 << K) - 1) & ((mask << j) | pw[j]);
				if(good[new_mask])
					add_t(dp[i][new_mask], dp[i-1][mask]);
			}
		}
	}
	int ans = 1;
	for(int i = 1; i <= n; ++i)
		ans = mt(ans, 10);
	for(int mask = 0; mask < (1 << K); ++mask) {
		add_t(ans, -dp[n][mask]);
	}
	// cout << dp[n][(1 << 4) + (1 << 11) + (1 << 16)] << endl;
	cout << ans << endl;
	return 0;
}