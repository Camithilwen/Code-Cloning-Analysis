#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<iostream>
#include <bitset>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
#define vec_unique(_a) _a.erase(std::unique(all(_a)), _a.end());
#define vvec vector<vector<ll>>
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }
ll mpower(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x = x * x % mod; p /= 2; } else { a = a * x % mod; p--; } }return a; }
ll ac(ll n, ll k) { ll a = 1; rep(i, 1, k) { a *= n - i + 1; a /= i; }return a; }
ll mc(ll n, ll m) { ll k = 1, l = 1; rep(i, n - m + 1, n + 1) k = k * i % mod; rep(i, 1, m + 1) l = l * i % mod; l = mpower(l, mod - 2); return k * l % mod; }
struct UnionFind {
	vector<int> par;
	UnionFind(int N) : par(N) { rep(i, 0, N)par[i] = i;}
	int root(int x) { return par[x] == x ? x : par[x] = root(par[x]);}
	void unite(int x, int y) {if (!same(x, y)) par[root(x)] = root(y); }
	bool same(int x, int y) {return root(x) == root(y);}
};
int main()
{
	int H, W;
	ll ans = 0;
	cin >> H >> W;
	vector<string> S(H);
	UnionFind tree(W * H);
	rep(i, 0, H)cin >> S[i];
	rep(i, 0, H) {
		rep(i2, 0, W) {
			if (i != H - 1 && S[i][i2] != S[i + 1][i2]) {
				tree.unite(i * W + i2, i * W + W + i2);
			}
			if (i2 != W - 1 && S[i][i2] != S[i][i2 + 1]) {
				tree.unite(i * W + i2, i * W + 1 + i2);
			}
		}
	}
	map<int, pair<int, int>>mp;
	rep(i, 0, H * W) {
		if(S[i / W][i % W] == '#')mp[tree.root(i)].first++;
		else mp[tree.root(i)].second++;
	}
	for (auto m : mp) {
		ans += (ll)m.second.first * m.second.second;
	}
	printf("%lld\n", ans);
	return 0;
}
