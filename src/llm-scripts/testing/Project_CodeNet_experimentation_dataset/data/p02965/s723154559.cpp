#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
vector<complex<double>>  DFT(vector<complex<double>> a) {
	int n = a.size();
	if (n == 1) return a;
	vector<complex<double>> a0(n / 2), a1(n / 2);
	REP(i, n) {
		if (i % 2 == 0) {
			a0[i / 2] = a[i];
		}
		else {
			a1[i / 2] = a[i];
		}
	}
	vector<complex<double>> inversed_a0 = DFT(a0), inversed_a1 = DFT(a1);
	vector<complex<double>> inversed_a(n);
	for (int i = 0; i < n; ++i) {
		complex<double> zeta = complex<double>(cos(2 * Ma_PI * i / n), sin(2 * Ma_PI * i / n));
		inversed_a[i] = inversed_a0[i % (n / 2)] + zeta * inversed_a1[i % (n / 2)];
	}
	return inversed_a;
}
vector<complex<double>> IDFT(vector<complex<double>> inversed_a) {
	int n = inversed_a.size();
	vector<complex<double>> now = DFT(inversed_a);
	reverse(now.begin(), now.end());
	for (int q = now.size() - 1; q >= 1; --q) {
		swap(now[q], now[q - 1]);
	}
	REP(i, n) {
		now[i] /= complex<double>(n, 0);
	}
	return now;
}
vector<complex<double>> conv(vector<complex<double>> a, vector<complex<double>> b) {
	int deg = a.size() + b.size() - 1;
	int n = 1;
	while (n < deg) n <<= 1;
	a.resize(n);
	b.resize(n);
	vector<complex<double>> inversed_a = DFT(a), inversed_b = DFT(b);
	vector<complex<double>> inversed_c(n);
	REP(i, n) {
		inversed_c[i] = inversed_a[i] * inversed_b[i];
	}
	return IDFT(inversed_c);
}
long long inv(long long now) {
	long long hoge = MOD - 2LL;
	long long ans = 1;
	while (hoge != 0) {
		if (hoge % 2 == 1) {
			ans *= now;
			ans %= MOD;
		}
		hoge /= 2;
		now *= now;
		now %= MOD;
	}
	return ans;
}
long long jun[2100000] = {};
long long gyaku[2100000] = {};
long long combination(long long a, long long b) {
	long long ans = jun[a];
	ans *= gyaku[a - b];
	ans %= MOD;
	ans *= gyaku[b];
	ans %= MOD;
	return ans;
}
long long no_limit(long long a, long long b) {
	return combination(a + b - 1, a);
}

int main() {
	jun[0] = 1;
	gyaku[0] = 1;
	for (long long i = 1; i < 2100000; ++i) {
		jun[i] = jun[i - 1] * i;
		jun[i] %= MOD;
		gyaku[i] = inv(jun[i]);
	}
	long long n, m;
	cin >> n >> m;
	long long ans = 0;
	long long tmp = 0;
	for (long long odd = m;; ++odd) {
		long long even = m - (odd - m) * 2LL;
		if (even < 0) break;
		tmp -= (n * no_limit(odd - m, n - 1)) % MOD;
		tmp += 2LL * MOD;
		tmp %= MOD;
		if (even > n) continue;
		long long geko = no_limit(odd, n);
		geko += tmp;
		geko += MOD;
		geko %= MOD;
		ans += geko * combination(n, even);
		ans %= MOD;
		if (n - 1 >= even) {
			ans += ((n * no_limit(odd - m, n - 1)) % MOD * combination(n - 1, even)) % MOD;
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}