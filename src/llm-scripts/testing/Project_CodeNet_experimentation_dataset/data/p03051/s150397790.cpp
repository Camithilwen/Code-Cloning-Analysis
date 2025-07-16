#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

LL N;
vector<LL>A;
vector<LL>xmos;
const LL MOD = 1000000007;

LL solvedp(vector<pair<LL, int>>& vec, LL lasval) {
	LL zero = 1, notz = 0;
	LL zpar = 1, npar = 0;
	for (auto p : vec) {
		if (p.first == 0) {
			zpar = (notz * p.second) % MOD;
			zero += zpar;
			zero %= MOD;
		}
		else {
			npar = (zero * p.second) % MOD;
			notz += npar;
			notz %= MOD;
		}
	}
	if (lasval == 0) {
		return zpar;
	}
	return npar;
}

int main() {
	cin >> N;
	LL xsum = 0;
	xmos.push_back(0);
	for (int i = 0; i < N; ++i) {
		LL tmp;
		cin >> tmp;
		A.push_back(tmp);
		xsum ^= tmp;
		xmos.push_back(xsum);
	}
	/*vector<LL>dp(N + 1);
	dp[1] = 1;
	LL odd = 1, eve = 0;
	for (int i = 2; i <= N; ++i) {
		if (i % 2) {
			dp[i]++;
			dp[i] += eve;
			dp[i] %= MOD;
			odd += dp[i];
			odd %= MOD;
		}
		else {
			dp[i] += odd;
			eve += dp[i];
			eve %= MOD;
		}
	}*/
	if (xsum != 0) {
		vector<pair<LL, int>>nowarr;
		for (int i = 1; i <= N; ++i) {
			if (xmos[i] == 0) {
				nowarr.push_back({ 0,1 });
			}
			if (xmos[i] == xsum) {
				nowarr.push_back({ xsum,1 });
			}
		}
		LL ans = solvedp(nowarr, xsum);
		cout << ans << endl;
	}
	else {
		map<LL, int>zerolas;
		map<LL, vector<pair<LL, int>>>arrs;
		int zerocnt = 0;
		LL zerotwo = 1;
		for (int i = 1; i <= N; ++i) {
			if (xmos[i] == 0) {
				zerocnt++;
				if (i < N) {
					zerotwo *= 2;
					zerotwo %= MOD;
				}
			}
			else {
				if (zerocnt != zerolas[xmos[i]]) {
					arrs[xmos[i]].push_back({ 0,zerocnt - zerolas[xmos[i]] });
					zerolas[xmos[i]] = zerocnt;
				}
				arrs[xmos[i]].push_back({ xmos[i],1 });
			}
		}
		LL ans = zerotwo;
		for (auto& elm : arrs) {
			if (elm.second.back().second != 0) {
				elm.second.push_back({ 0,1 });
			}
			ans += solvedp(elm.second, 0);
			ans %= MOD;
		}
		cout << ans << endl;
	}
	return 0;
}
