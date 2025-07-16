
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
static const LLONG MOD_NUM = 1000000007; //998244353;

template<class _T> static void get(_T& a) {
	std::cin >> a;
}
template<class _T> static void get(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void get(_T& a, _T& b, _T& c) {
	std::cin >> a >> b >> c;
}
template <class _T> static _T tp_pow(int base, int exp)
{
	_T ans = 1;

	for (int i = 0; i < exp; i++) {
		ans *= (_T)base;
	}
	return ans;
}

static void D();

int main()
{
	D();
	fflush(stdout);
	return 0;
}

static void D()
{
	int N, M;
	get(N, M);

	std::vector<int> num(N, -1);

	for (int i = 0; i < M; i++) {
		int s, c;
		get(s, c);

		if ((s > N) || ((num[s - 1] != -1) && (num[s - 1] != c))) {
			printf("-1\n");
			return;
		}
		num[s - 1] = c;
	}

	if (num[0] == 0 && N > 1) {
		printf("-1\n");
		return;
	}
	else if (num[0] == -1 && N > 1) num[0] = 1;

	for (int i = 0; i < N; i++) {
		if (num[i] < 0) num[i] = 0;
		printf("%d", num[i]);
	}
	putchar('\n');
}

