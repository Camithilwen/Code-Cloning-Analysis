#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <bitset>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()

#pragma region UnionFind
struct UnionFind
{
	vector<int> par;

	UnionFind(int n) : par(n, -1) {}
	void init(int n) { par.assign(n, -1); }

	int root(int x)
	{
		if (par[x] < 0) return x;
		else return par[x] = root(par[x]);
	}

	bool issame(int x, int y)
	{
		return root(x) == root(y);
	}

	bool merge(int x, int y)
	{
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}

	int size(int x)
	{
		return -par[root(x)];
	}
};
#pragma endregion
#pragma region GCD
int gcd(int a, int b)
{
	if (a%b == 0)return b;
	return gcd(b, a%b);
}
#pragma endregion
#pragma region chmin
template<class T> inline bool chmin(T& a, T b)
{
	if (a > b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma region chmax
template<class T> inline bool chmax(T& a, T b)
{
	if (a < b)
	{
		a = b;
		return true;
	}
	return false;
}
#pragma endregion
#pragma endregion


int main()
{
	int a, b; cin >> a >> b;
	vector<string> res;
	rep(i, 50)
	{
		string s = "";
		rep(j, 100)s += '.';
		res.push_back(s);
	}
	rep(i, 50)
	{
		string s = "";
		rep(j, 100)s += '#';
		res.push_back(s);
	}
	int x = 0;
	int y = 0;
	--a, --b;
	while (b > 0)
	{
		if (y >= 100)
		{
			x += 2;
			y = 0;
		}
		res[x][y] = '#';
		y += 2;
		--b;
	}
	x = 51;
	y = 0;
	while (a > 0)
	{
		if (y >= 100)
		{
			x += 2;
			y = 0;
		}
		res[x][y] = '.';
		y += 2;
		--a;
	}
	cout << 100 << " " << 100 << endl;
	rep(i, 100)cout << res[i] << endl;
}