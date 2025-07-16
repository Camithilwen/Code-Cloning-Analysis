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
ll gcd(ll a, ll b)
{
	if (b == 0)return a;
	return gcd(b, a%b);
}
#pragma endregion
#pragma region LCM
ll lcm(ll a, ll b)
{
	return a / gcd(a, b) * b;
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

#pragma region イベントソート
using type = pair<int, ll>; // 1: query, 0; delete, -1: insert
using event = pair<ll, type>;
#pragma endregion

int main()
{
	int n, q; cin >> n >> q;
	vector<event> v;
	rep(i, n)
	{
		ll s, t, x; cin >> s >> t >> x;
		v.push_back({ s - x,{-1,x} });
		v.push_back({ t - x,{0,x} });
	}
	rep(i, q)
	{
		ll d; cin >> d;
		v.push_back({ d,{1,0} });
	}
	sort(all(v));
	multiset<ll> s;
	for (auto p : v)
	{
		ll e = p.second.first;
		ll pos = p.second.second;
		if (e == -1) s.insert(pos);
		else if (e == 0)s.erase(s.lower_bound(pos));
		else
		{
			if (s.empty())cout << -1 << endl;
			else cout << *s.begin() << endl;
		}
	}
}