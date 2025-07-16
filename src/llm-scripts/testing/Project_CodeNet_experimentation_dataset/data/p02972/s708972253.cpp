#pragma region header
#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cctype>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
#include <cstring>
#include <array>
// ===============================================================
//using系
#pragma region header
using namespace std;
using lint = long long;
using ld = long double;
using ulint = unsigned long long;
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr lint mod = 1000000007;
constexpr long double pi = 3.141592653589793238462643383279;
#pragma endregion
// ========================================================================
//define
#define INF (lint)10000000000000000;
#define mod (int)1000000007
#pragma region header
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
#pragma endregion
#pragma endregion

lint dp[1000][2020];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> d(n);
	vector<bool> ans(n, false);
	for (int i = 0; i < n; i++) cin >> d[i];
	for (int i = n - 1; i >= 0; i--) {
		int cnt = 0;
		for (int j = i; j < n; j += i + 1) {
			if (ans[j]) cnt++;
		}
		if (cnt % 2 != d[i]) ans[i] = true;
	}
	int cnt = 0;
	lint a = 0;
	for (int i = 0; i < n; i++) {
		if (ans[i]) a++;
	}
	cout << a << endl;
	for (int i = 0; i < n; i++) {
		if (ans[i]) {
			cout << i + 1;
			cnt++;
			if (cnt == a) cout << endl;
			else cout << ' ';
		}
	}

	return 0;
}