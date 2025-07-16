
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
static const LLONG MOD_NUM = 1000000007;

template<class _T> static void getval(_T& a) {
	std::cin >> a;
}
template<class _T> static void getval(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getval(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_abs(_T a) {
	if (a < (_T)0) {
		a *= (_T)-1;
	}
	return a;
}
template <class _T> static void tp_swap(_T& right, _T& left) {
	//	usage:  tp_swap<type name>(a, b);
	_T tmp = right;
	right = left;
	left = tmp;
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
	int sx, sy, tx, ty;
	getval(sx, sy);
	getval(tx, ty);

	int dx = tx - sx;
	int dy = ty - sy;
	std::string ans;
	for (int i = 0; i < dx; i++) {
		ans += 'R';
	}
	for (int i = 0; i < dy; i++) {
		ans += 'U';
	}
	for (int i = 0; i < dx; i++) {
		ans += 'L';
	}
	for (int i = 0; i < dy; i++) {
		ans += 'D';
	}

	ans += 'D';
	for (int i = 0; i <= dx; i++) {
		ans += 'R';
	}
	for (int i = 0; i <= dy; i++) {
		ans += 'U';
	}
	ans += 'L';
	ans += 'U';
	for (int i = 0; i <= dx; i++) {
		ans += 'L';
	}
	for (int i = 0; i <= dy; i++) {
		ans += 'D';
	}
	ans += 'R';

	std::cout << ans << std::endl;
}
