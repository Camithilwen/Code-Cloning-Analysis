
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

static void exec();

int main()
{
	exec();
	fflush(stdout);
	return 0;
}

static void exec()
{
	int N;
	get(N);

	std::vector<std::pair<LLONG, LLONG>> plate(N);
	for (int i = 0; i < N; i++) {
		get(plate[i].first, plate[i].second);
	}

	auto psum = [](const std::pair<LLONG, LLONG>& a, const std::pair<LLONG, LLONG>& b) {
		return (a.first + a.second) > (b.first + b.second);
	};
	std::sort(plate.begin(), plate.end(), psum);

	LLONG tak = 0, aok = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2) {
			aok += plate[i].second;
		}
		else {
			tak += plate[i].first;
		}
	}
	printf("%lld\n", tak - aok);
}
