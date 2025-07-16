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
#define r_sort(_x) sort(_x, std::greater<int>())
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
typedef struct {
	int y, x, y2, x2;
}p4;
int main()
{
	int h, w;
	ll M = 0;
	vector<p4> k;
	string ans = "";
	cin >> h >> w;
	vector<vector<int>> c(h, vector<int>(w));
	rep(i, 0, h) {
		rep(i2, 0, w) {
			cin >> c[i][i2];
		}
	}
	int x, y, px = -1, py;
	rep(i, 0, h) {
		rep(i2, 0, w) {
			y = i, x = i % 2 ? (w - i2 - 1) : i2;
			if (px != -1 && c[py][px] % 2) {
				c[py][px]--;
				c[y][x]++;
				k.push_back({py+1,px+1, y+1, x+1});
				M++;
			}
			px = x, py = y;
		}
	}
	printf("%lld\n", M);
	for (auto it : k) {
		printf("%d %d %d %d\n", it.y, it.x, it.y2, it.x2);
	}
	return 0;
}
