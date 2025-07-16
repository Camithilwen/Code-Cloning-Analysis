#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

template <typename T>
struct RollingHash
{
	int size;
	int n;
	ll factor = 1;
	ll b = 0;
	ll mod = 0;
	ll hash = 0;
	vector<T> list;
	int num = 0;
	int head = 0;

	void init(int _n, ll _b = (ll)1e8 + 7, ll _mod = (ll)1e9 + 7)
	{
		n = _n;
		b = _b;
		list.reserve(n);
		mod = _mod;
		auto temp = 1ll;
		for (auto i = 0; i < n; ++i)
		{
			factor = temp;
			temp = temp * b % mod;
		}
	}

	void add(ll val)
	{
		if ((int)list.size() >= n)
		{
			hash = (((hash - list[head] * factor) % mod) + mod) % mod;
			list[head] = val;
			head = (head + 1) % n;
		}
		else
		{
			list.push_back(val);
		}
		hash = hash * b % mod;
		hash = (hash + val) % mod;
	}

	ll getHash() { return hash; }
};

int main()
{
	int N;
	cin >> N;
	vector<ll> a(N);
	vector<ll> b(N);
	for (auto i = 0; i < N; ++i)
	{
		ll temp;
		cin >> temp;
		a[i] = temp;
		a.push_back(temp);
	}
	for (auto& temp : b)
	{
		cin >> temp;
	}

	vector<ll> x;
	for (auto i = 0; i < N; ++i)
	{
		x.push_back(b[0] ^ a[i]);
	}

	auto bitNum = 31;
	auto mod = (ll)1e9 + 7;
	vector<ll> rollingHashFactor = { (ll)1e8 + 7 };
	vector<vector<vector<RollingHash<ll>>>> hashA
		(bitNum, vector<vector<RollingHash<ll>>>(2, vector<RollingHash<ll>>((int)rollingHashFactor.size())));
	vector<vector<RollingHash<ll>>> hashB
		(bitNum, vector<RollingHash<ll>>((int)rollingHashFactor.size()));

	for (auto i = 0; i < bitNum; ++i)
	{
		for (auto k = 0; k < N; ++k)
		{
			auto val = (b[k] >> i) & 1;
			for (auto l = 0; l < (int)rollingHashFactor.size(); ++l)
			{
				if (k == 0)
				{
					hashB[i][l].init(N, rollingHashFactor[l], mod);
				}
				hashB[i][l].add(val);
			}
		}
	}

	for (auto i = 0; i < bitNum; ++i)
	{
		for (auto j = 0; j < 2; ++j)
		{
			for (auto k = 0; k < N; ++k)
			{
				auto val = ((a[k] >> i) ^ j) & 1;
				for (auto l = 0; l < (int)rollingHashFactor.size(); ++l)
				{
					if (k == 0)
					{
						hashA[i][j][l].init(N, rollingHashFactor[l]);
					}
					hashA[i][j][l].add(val);
				}
			}
		}
	}

	vector<pair<int, ll>> ans;
	for (auto k = 0; k < N; ++k)
	{
		auto match = true;
		for (auto i = 0; i < bitNum; ++i)
		{
			int j = (x[k] >> i) & 1;
			for (auto l = 0; l < (int)rollingHashFactor.size(); ++l)
			{
				if (hashB[i][l].getHash() != hashA[i][j][l].getHash())
				{
					match = false;
					break;
				}
			}

			if (match == false)
			{
				break;
			}
		}

		if (match != false)
		{
			ans.push_back({ k, x[k] });
		}

		for (auto i = 0; i < bitNum; ++i)
		{
			for (auto j = 0; j < 2; ++j)
			{
				auto val = ((a[k + N] >> i) ^ j) & 1;
				for (auto l = 0; l < (int)rollingHashFactor.size(); ++l)
				{
					hashA[i][j][l].add(val);
				}
			}
		}
	}

	for (auto& pair : ans)
	{
		cout << pair.first << " " << pair.second << endl;
	}

	return 0;
}