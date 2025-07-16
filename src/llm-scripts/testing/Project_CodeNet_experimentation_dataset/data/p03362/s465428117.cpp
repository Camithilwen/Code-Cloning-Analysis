
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
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
template<class _T> static void getint(_T& a, _T& b, _T& c) {
	const char* fmt = " %d %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld %lld";
	}

	if (scanf(fmt, &a, &b, &c) < 0) {
		printf("g3int Error\n");
	}
}

static void ABC096D();

#if 1
int main()
{
	ABC096D();
	fflush(stdout);
	return 0;
}
#endif

template <class _T> void tp_getPrimes(_T targ, std::map<_T, _T>& primes)
{
	_T target = targ;
	_T i = 2;
	while ((i * i) <= target) {
		if ((target % i) == 0) {
			target /= i;
			primes[i]++;
		}
		else {
			i++;
		}
	}
	if (target > 1) {
		primes[target]++;
	}
}

static void ABC096D()
{
	int N;
	getint(N);
	
	std::vector<int> primeNumbers;

	for (int i = 2; i <= 55555; i++) {
		std::map<int, int> primes;
		tp_getPrimes<int>(i, primes);
		if ((primes.size() == 1) && (primes.begin()->second == 1)){
			primeNumbers.push_back(primes.begin()->first);
		}
	}

	int count = 0;
	std::vector<int> ans(N);
	auto it = primeNumbers.begin();
	while ((it != primeNumbers.end()) && (count < N)) {
		if ((*it % 5) == 1) {
			ans[count] = *it;
			count++;
		}
		it++;
	}
	std::string str;
	for (int i = 0; i < N; i++) {
		char tmp[16] = { 0 };
		sprintf(tmp, "%d", ans[i]);

		if (i) {
			str += ' ';
		}
		str += tmp;
	}
	printf("%s\n", str.c_str());
}
