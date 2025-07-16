#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

#define int long long

const int MOD = 998244353;
const int N = 1e5 + 5;

int add(int a, int b) {
	return (a + b) % MOD;
}

int mul(int a, int b) {
	return (a * b) % MOD;
}

int binpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int divv(int a, int b) {
	return mul(a, binpow(b, MOD - 2));
}

int f[N];

void init() {
	f[0] = 1; 
	for (int i = 1; i < N; i++) {
		f[i] = mul(i, f[i - 1]);
	}
}

int C(int n, int k) {
	return divv(f[n], mul(f[k], f[n - k]));
}

int cnt_array(int cnt, int n) {
	if (cnt == 0) return 0;
	return C(n + cnt - 1, n);
}


int solve(int db, int on, int n, int rk) {
	rk -= db;
	int ans = 0;
	for (int sel = 0; sel <= db && sel <= n; sel++) {
		int cnt = cnt_array(on + sel, n - sel);
		cnt = mul(cnt, C(db, sel));
		cnt = mul(cnt, binpow(2, sel));
		ans = add(ans, cnt);
	}
	return ans;
}

int n, k;

int solve_i(int i) {
	int db = 0;
	int on = 0;
	int mid = 0;
	for (int x = 1; x <= k; x++) {
		if (1 <= (i - x) && (i - x) <= k) {
			if (2 * x == i) {
				mid = 1;
			} else {
				db++;
			}
		} else {
			on++;
		}
	}
	db /= 2;
	if (mid) {
		int ff = solve(db, on, n, k - 1);
		int ss = solve(db, on, n - 1, k - 1);
		return add(ff, ss);
	} else {
		return solve(db, on, n, k);
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();

	cin >> k >> n;
	for (int i = 2; i <= 2 * k; i++) {
		cout << solve_i(i) << '\n';
	}
}
