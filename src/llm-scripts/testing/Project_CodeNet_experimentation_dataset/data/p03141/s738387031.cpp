
#include <stdio.h>
#include <string.h>
#include <limits.h>
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

template<class _T> static void getint(_T& a) {
	std::cin >> a;
}
template<class _T> static void getint(_T& a, _T& b) {
	std::cin >> a >> b;
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
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
	int N;
	getint(N);

	std::vector<std::pair<LLONG, LLONG>> plates(N);
	for (int i = 0; i < N; i++) {
		getint(plates[i].first, plates[i].second);
	}

	std::sort(plates.begin(), plates.end(),
		[](const std::pair<LLONG, LLONG>& a, const std::pair<LLONG, LLONG>& b) {
		return (a.first + a.second) > (b.first + b.second);
	});

	bool tkhs = true;
	std::vector<std::pair<LLONG, LLONG>> tk, ao;
	for (int i = 0; i < N; i++) {
		if (tkhs) {
			tk.push_back(plates[i]);
			tkhs = false;
		}
		else {
			ao.push_back(plates[i]);
			tkhs = true;
		}
	}
	
	LLONG tkSum = 0;
	for (auto it = tk.begin(); it != tk.end(); it++) {
		tkSum += it->first;
	}
	LLONG aoSum = 0;
	for (auto it = ao.begin(); it != ao.end(); it++) {
		aoSum += it->second;
	}

	printf("%lld\n", tkSum - aoSum);
}
