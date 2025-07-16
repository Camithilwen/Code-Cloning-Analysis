#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<long long> x(n);
	vector<long long> y(m);
	for (auto i = 0; i < n; ++i)
	{
		cin >> x[i];
	}
	for (auto i = 0; i < m; ++i)
	{
		cin >> y[i];
	}

	auto sumX = 0ll;
	auto mod = (long long)1e9 + 7;
	for (auto i = 1; i < n; ++i)
	{
		auto diff = x[i] - x[i - 1];
		sumX += (((diff * i) % mod) * (n - 1 - i + 1)) % mod;
		sumX %= mod;
	}

	auto sum = 0ll;
	for (auto i = 1; i < m; ++i)
	{
		auto diff = y[i] - y[i - 1];
		sum += (((((diff * i) % mod) * (m - 1 - i + 1)) % mod) * sumX) % mod;
		sum %= mod;
	}

	cout << sum << endl;

	return 0;
}