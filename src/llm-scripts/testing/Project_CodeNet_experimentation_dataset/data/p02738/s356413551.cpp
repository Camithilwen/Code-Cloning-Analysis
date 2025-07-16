/*

Code for problem D by cookiedoth
Generated 22 Mar 2020 at 06.57 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

=_=
>_<
o_O

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int MOD;

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

void add(int &a, int b) {
	a = (a + b) % MOD;
}

int power(int a, int deg) {
	int res = 1;
	while (deg) {
		if (deg & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		deg >>= 1;
	}
	return res;
}

int inverse(int a) {
	return power(a, MOD - 2);
}

const int mx = 6010;
int n, dp[mx][2 * mx], inv[2 * mx], dim2_zero;

signed main() {
	fast_io();
	vector<int> delta = {0, 1, -1, 0};
	cin >> n >> MOD;
	dim2_zero = 3 * n;
	inv[1] = 1;
	for (int i = 2; i <= 3 * n; ++i) {
		inv[i] = mul(MOD - MOD / i, inv[MOD % i]);
	}
	dp[0][dim2_zero] = 1;
	for (int s = 0; s < 3 * n; ++s) {
		for (int d = 0; d <= 2 * dim2_zero; ++d) {
			for (int bl = 1; bl <= 3; ++bl) {
				int s1 = s + bl;
				int d1 = d + delta[bl];
				if (s1 <= 3 * n && d1 >= 0 && d1 <= 2 * dim2_zero) {
					add(dp[s1][d1], mul(dp[s][d], inv[s1]));
				}
			}
		}
	}
	int ans = 0;
	for (int bal = dim2_zero; bal <= 2 * dim2_zero; ++bal) {
		add(ans, dp[3 * n][bal]);
	}
	for (int i = 1; i <= 3 * n; ++i) {
		ans = mul(ans, i);
	}
	cout << ans << endl;
}
