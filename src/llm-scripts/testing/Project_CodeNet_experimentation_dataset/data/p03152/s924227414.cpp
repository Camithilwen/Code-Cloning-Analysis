#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int N = 1e6 + 1;
const int MOD = 1e9 + 7;

int mul(int a, int b) {
	return 1LL * a * b % MOD;
}

int sub(int a, int b) {
	return (a - b + MOD) % MOD;
}

int p_col[N];
int p_row[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fill(p_col, p_col + N, -1);
	fill(p_row, p_row + N, -1);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		p_row[x] = i;
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		x--;
		p_col[x] = i;
	}
	int ans = 1;
	int cnt = 0;
	int free_col = 0;
	int free_row = 0;
	for (int i = n * m - 1; i >= 0; i--) {
		if (p_row[i] != -1 && p_col[i] != -1) {
			free_row++;
			free_col++;
		} else if (p_row[i] != -1) {
			ans = mul(ans, free_col);
			free_row++;
		} else if (p_col[i] != -1) {
			ans = mul(ans, free_row);
			free_col++;
		} else {
			ans = mul(ans, sub(mul(free_col, free_row), cnt));
		}
		cnt++;
	}
	cout << ans << '\n';
}

