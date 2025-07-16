#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int x, int y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
bool solve(int n, vector<int> a) {
	int parity = 0, odds = 0, minelem = a[0];
	for (int i = 0; i < n; ++i) {
		parity = (parity + a[i] - 1) % 2;
		if (a[i] & 1) ++odds;
		minelem = min(minelem, a[i]);
	}
	if (parity == 1) return true;
	if (minelem == 1 || odds >= 2) return false;
	int g = -1;
	for (int i = 0; i < n; ++i) {
		if (a[i] & 1) --a[i];
		if (i == 0) g = a[i];
		else g = gcd(g, a[i]);
	}
	for (int i = 0; i < n; ++i) {
		a[i] /= g;
	}
	bool res = solve(n, a);
	return !res;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	bool res = solve(n, a);
	cout << (res ? "First" : "Second") << endl;
	return 0;
}