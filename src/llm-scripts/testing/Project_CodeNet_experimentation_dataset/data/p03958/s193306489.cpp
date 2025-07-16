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
	
	int S, n;
	cin >> S >> n;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	int mx = *max_element(a.begin(), a.end());
	if (mx > (S + 1) / 2) {
		cout << (mx - (S + 1) / 2) * 2 - (S % 2 == 0) << endl;
	} else {
		cout << 0 << endl;
	}
}