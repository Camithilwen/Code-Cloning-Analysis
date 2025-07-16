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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	for (int t = 0; t < k; t++) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			int l = i - a[i];
			int r = i + a[i];
			v[max(0, l)]++;
			if (r + 1 < n) v[r + 1]--;
		}
		for (int i = 1; i < n; i++) {
			v[i] += v[i - 1];
		}
		a = v;
		if (*min_element(a.begin(), a.end()) == n) break;
	}
	for (auto t : a) {
		cout << t << ' ';
	}
	cout << '\n';
}
