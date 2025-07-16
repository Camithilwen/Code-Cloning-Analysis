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
#define eps 1e-5
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
long long grid[600000] = {};
vector<long long> finding_X[2000000];
long long zero[600000] = {};
long long cnt_zero(long long l, long long r) {
	long long ans = zero[r];
	if (l != 0) {
		ans -= zero[l - 1];
	}
	return ans;
}
pair<long long,long long> calc(long long X) {
	pair<long long, long long> ans = make_pair(1, 0);
	if (finding_X[X].size() != 0) {
		ans.second = 1;
	}
	for (int i = 1; i < finding_X[X].size(); ++i) {
		long long zero_move = cnt_zero(finding_X[X][i - 1], finding_X[X][i]);
		ans.first += zero_move * ans.second;
		ans.first %= MAX_MOD;
		ans.second += ans.first;
		ans.second %= MAX_MOD;
	}
	return ans;
}
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	REP(i, n) {
		cin >> grid[i + 1];
		grid[i + 1] ^= grid[i];
	}
	for (int i = 1; i <= n; ++i) {
		zero[i] = zero[i - 1];
		if (grid[i] == 0) {
			zero[i]++;
		}
		else {
			finding_X[grid[i]].push_back(i);
		}
	}
	if (grid[n] != 0) {
		cout << calc(grid[n]).first << endl;
		return 0;
	}
	long long ans = 1;
	for (int i = 0; i < zero[n]-1; ++i) {
		ans *= 2;
		ans %= MAX_MOD;
	}
	for (int i = 1; i < (1 << 20); ++i) {
		ans += calc(i).second;
		ans %= MAX_MOD;
	}
	cout << ans << endl;
}