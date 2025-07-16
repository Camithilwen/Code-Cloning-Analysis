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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 30000000000000LL
#define GOLD 1.61803398874989484820458
const long long MAX_MOD = 1e6 + 3;
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
long long powering(long long now,long long now_go){
	long long ans = 1;
	while (now_go != 0) {
		if (now_go % 2 == 1) {
			ans *= now;
			ans %= MAX_MOD;
		}
		now *= now;
		now %= MAX_MOD;
		now_go /= 2;
	}
	return ans;
}
long long inv(long long now) {
	return powering(now, MAX_MOD - 2LL);
}
long long d;
long long geko[32] = {};
long long bobo[30] = {};
long long solve(long long now, long long now_digit, long long L) {
	if (L / 2 == now_digit) {
		if (L % 2 == 0) {
			if (d == now) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			if (d == now) {
				return 10LL;
			}
			else {
				return 0LL;
			}
		}
	}
	long long ans = 0;
	for (long long i = -9; i <= 9; ++i) {
		long long tea = geko[L - now_digit - 1] - geko[now_digit];
		tea *= i;
		tea += now;
		if (tea >= 0) {
			if (tea % geko[now_digit + 1] == d % geko[now_digit + 1]) {
				//ok
				long long geko = solve(tea, now_digit + 1, L);
				if (geko == 0) continue;
				if (now_digit == 0) {
					bobo[i + 9]--;
				}
				ans += geko * bobo[i+9];
				if (now_digit == 0) {
						bobo[i + 9]++;
				}
			}
		}
		else {
			tea += geko[18];
			if (tea % geko[now_digit + 1] == d % geko[now_digit + 1]) {
				long long geko = solve(tea - bobo[18], now_digit + 1, L);
				if (geko == 0)continue;
				if (now_digit == 0) {
						bobo[i + 9]--;
				}
				ans += geko * bobo[i + 9];
				if (now_digit == 0) {
						bobo[i + 9]++;
				}
			}
			tea -= geko[18];
		}
	}
	return ans;
}
int main() {
	for (int i = 0; i <= 9; ++i) {
		for (int q = 0; q <= 9; ++q) {
			bobo[i - q + 9]++;
		}
	}
	geko[0] = 1;
	for (int i = 1; i <= 18; ++i) {
		geko[i] = 10LL * geko[i-1];
	}
	cin >> d;
	if (d % 9 != 0) {
		cout << 0 << endl;
		return 0;
	}
	int len = to_string(d).length();
	long long ans = 0;
	for (long long digit = len; digit <= len * 2; ++digit) {
		ans += solve(0, 0, digit);
	}
	cout << ans << endl;
}
