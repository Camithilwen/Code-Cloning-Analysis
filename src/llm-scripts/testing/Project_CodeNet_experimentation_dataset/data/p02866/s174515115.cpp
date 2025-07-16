
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 998244353;//1000000007;

template<class _T> static void getval(_T& a) {
	std::cin >> a;
}
template<class _T> static void getval(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getval(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}

static void exec();

int main()
{
	exec();
	fflush(stdout);
	return 0;
}

template <class _T> static _T tp_modpow(_T a, _T n, _T mod = (_T)1) {
	_T ans = 1;
	while (n > 0) {
		if (n & 1) {
			ans = (ans * a) % mod;
		}
		a = (a * a) % mod;
		n >>= 1;
	}
	return ans;
}

static void exec()
{
	int N;
	getval(N);
	
	int d0;
	getval(d0);

	std::vector<LLONG> count(N, 0);
	for (int i = 1; i < N; i++) {
		int di;
		getval(di);
		count[di]++;
	}

	if (d0 || count[0]) {
		printf("0\n");
		return;
	}
	count[0]++;

	LLONG ans = 1;
	for (int i = 1; i < N; i++) {
		LLONG val = tp_modpow(count[i - 1], count[i], MOD_NUM);
		ans = (ans * val) % MOD_NUM;
	}
	printf("%lld\n", ans);
}
