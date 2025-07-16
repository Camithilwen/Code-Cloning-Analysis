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

typedef long long ll;

const int N = 401;
const vector<int> dx = {0, 0, 1, -1};
const vector<int> dy = {1, -1, 0, 0};

int used[N * N];
vector<int> g[N * N];

int n, m;
int a[N][N];

int get(int i, int j) {
	return i * m + j;
}

int ok(int i, int j) {
	return 0 <= i & i < n && 0 <= j && j < m;
}

void dfs(int cur, int &c0, int &c1) {
	used[cur] = 1;
	if (a[cur / m][cur % m] == 0) {
		c0++;
	} else {
		c1++;
	}
	for (auto t : g[cur]) {
		if (!used[t]) {
			dfs(t, c0, c1);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			a[i][j] = (c == '#');
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int f = 0; f < 4; f++) {
				int i1 = i + dx[f];
				int j1 = j + dy[f];
				if (ok(i1, j1) && a[i][j] != a[i1][j1]) {
					g[get(i, j)].push_back(get(i1, j1));
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n * m; i++) {
		if (!used[i]) {
			int c0 = 0;
			int c1 = 0;
			dfs(i, c0, c1);
			ans += c0 * c1;
		}
	}
	cout << ans << '\n';
}
