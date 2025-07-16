#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;
using ll = long long int;
using dd = long double;
const ll MOD = 1e9 + 7;
const dd PI = 3.1415926535;

class UnionFind {
	std::vector<int> p;

public:
	UnionFind(int n) : p(n, -1) {}

	int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }

	bool same(int x, int y) { return root(x) == root(y); }

	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (p[y] < p[x]) std::swap(x, y);
		if (p[x] == p[y]) --p[x];
		p[y] = x;
		return true;
	}
};

ll fast(ll n, ll k) {
	if (k == 0) {
		return 1;
	}
	if (k == 1) {
		return n;
	}
	if (k % 2 == 0) {
		ll tmp = fast(n, k / 2);
		return tmp * tmp % MOD;
	}
	else {
		ll tmp = fast(n, k / 2);
		tmp = tmp * tmp % MOD;
		return n * tmp % MOD;
	}
}


int main() {
	ll N;
	cin >> N;

	cout << 180 * (N - 2) << endl;
}