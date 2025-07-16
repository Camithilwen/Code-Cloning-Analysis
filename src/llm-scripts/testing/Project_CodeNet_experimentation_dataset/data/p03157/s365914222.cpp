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


int main()
{
	int h, w; cin >> h >> w;
	vector<string> s(h); rep(i, h)cin >> s[i];
	ll res = 0;
	int d[] = { 0,1,0,-1 };
	vector<vector<bool>> passed(h, vector<bool>(w));
	rep(i, h)rep(j, w)
	{
		if (s[i][j] == '.' || passed[i][j])continue;
		passed[i][j] = true;
		queue<pair<int, int>> q;
		q.push(make_pair(i, j));
		ll B = 1, W = 0;
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			rep(k, 4)
			{
				int nx = x + d[k];
				int ny = y + d[k ^ 1];
				if (nx < 0 || h <= nx || ny < 0 || w <= ny)continue;
				if (passed[nx][ny])continue;
				if (s[x][y] != s[nx][ny])
				{
					q.push(make_pair(nx, ny));
					passed[nx][ny] = true;
					if (s[nx][ny] == '.')++W;
					else ++B;
				}
			}
		}
		res += B * W;
	}
	cout << res << endl;
}