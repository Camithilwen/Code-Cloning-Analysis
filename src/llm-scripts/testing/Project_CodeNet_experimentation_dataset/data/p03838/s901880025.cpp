
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <bitset>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 998244353; //1000000007;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}

static void exec();

int main()
{
	exec();
	fflush(stdout);
	return 0;
}

static void exec()
{
	int x, y;
	get(x, y);
	
	int ans = 0;
	if (tp_abs(x) < tp_abs(y)) {
		if (x < 0) {
			ans++;
		}
		ans += tp_abs(y) - tp_abs(x);
		if (y < 0) {
			ans++;
		}
	}
	else {
		if (x > 0) {
			ans++;
		}
		ans += tp_abs(x) - tp_abs(y);
		if (y > 0) {
			ans++;
		}
	}
	printf("%d\n", ans);
}
