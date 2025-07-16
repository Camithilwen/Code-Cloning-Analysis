#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;

vector<int> ant;

int main() {
#ifdef HOME
	freopen("agc01d.in", "r", stdin);
	freopen("agc01d.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, odd(0);

	vector<int> v;
	cin >> n >> m;
	v.resize(m);
	for (auto &i: v) {
		cin >> i;
		if (i % 2)
			odd+= 1; }

	if (odd > 2) {
		cout << "Impossible\n";
		return 0; }

	ant.reserve(n);

	partition(begin(v), end(v), [&](const int &x) { return x % 2; });
	partition(begin(v) + 1, end(v), [&](const int &x) { return 1 - x % 2; });

	ant.push_back(v[0] - 1);
	n-= v[0] - 1;
	for (int i = 1; i < m; ++i) {
		ant.push_back(v[i]);
		n-= v[i]; }

	if (n > 0) {
		if (v.back() == 1 || m != 1)
			ant.back()+= n;
		else
			ant.push_back(n); }

	ant.erase(remove(begin(ant), end(ant), 0), end(ant));

	for  (auto i: v)
		cout << i << ' ';
	cout << '\n' << ant.size() << '\n';
	for (auto i: ant)
		cout << i << ' ';
	cout << endl;

	return 0; }

