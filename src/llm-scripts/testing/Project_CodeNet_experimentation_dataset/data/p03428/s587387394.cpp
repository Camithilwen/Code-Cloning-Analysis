#define _USE_MATH_DEFINES
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<random>
#include<functional>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<bitset>
#include<unordered_map>
#include<climits>
#include<fstream>
using namespace std;
typedef long long ll;
typedef long double ld;
#define all(a) (a).begin(),(a).end()
#define EPS (1e-5)
#define bit(n,k) ((n>>k)&1)
const ll Mod = 1000000007;
const ll mod = 998244353;
struct H {
	ld x, y;
	bool operator<(const H& b) const {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
	bool operator>(const H& b) const {
		if (x != b.x) return x > b.x;
		return y > b.y;
	}
	bool operator==(const H& b) const { return x == b.x && y == b.y; }
	bool operator!=(const H& b) const { return (*this) != b; }
};
struct P {
	ll pos, cost;
	bool operator<(const P& b) const { return cost < b.cost; }
	bool operator>(const P& b) const { return cost > b.cost; }
};
struct B {
	ll to, cost;
};
struct E {
	ll from, to, cost;
	bool operator<(const E& b) const { return cost < b.cost; }
	bool operator>(const E& b) const { return cost > b.cost; }
};
template<typename T, typename U>
void chmin(T& a, U b) {
	if (a > b) a = b;
}
template<typename T, typename U>
void chmax(T& a, U b) {
	if (a < b) a = b;
}
template<typename T>
T max_0(T a) {
	if (a < 0) return 0;
	return a;
}
template<typename T>
T min_0(T a) {
	if (a > 0) return 0;
	return a;
}
ll read() {
	ll u;
	ll k = scanf("%lld", &u);
	return u;
}
ll gcd(ll i, ll j) {
	if (i > j) swap(i, j);
	if (i == 0) return j;
	return gcd(j % i, i);
}
ll mod_pow(ll x, ll n, ll p) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % p;
		x = x * x % p;
		n >>= 1;
	}
	return res;
}//x^n%p
const ll Inf = 3023372036854775807;
const int inf = 1500000000;
#define int long long
//----------------------------------------------------
int n;
struct A { ld x, y; int t; } a[200000];
bool operator<(A a, A b) { if (a.x != b.x) return a.x > b.x; return a.y > b.y; }

ld sgarea(A a, A b, A c) {
	return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2;
}
H b[400000];
ld d[2000];
signed main() {
	cin >> n;
	H sum = { 0,0 };
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		sum.x += a[i].x, sum.y += a[i].y;
		a[i].t = i;
	}
	sum.x /= n, sum.y /= n; sum.x += 0.01, sum.y -= 0.01;
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		b[i] = H{ atan2(a[i].y - sum.y, a[i].x - sum.x) ,(ld)i };
		if (b[i].x < 0) b[i].x += 2 * M_PI;
	}
	sort(b, b + n);
	for (int i = 1; i < 3; i++)for (int j = 0; j < n; j++) b[i * n + j] = b[j];
	vector<int>v;
	int s = 0;
	for (int i = 0; i < n; i++) if (b[i].y == 0) s = i;
	v.push_back(b[s].y); v.push_back(b[s + 1].y);
	for (int i = 2; i <= n; i++) {
		do {
			if (sgarea(a[v[v.size() - 2]], a[v[v.size() - 1]], a[(int)b[i + s].y]) < 0) {
				v.pop_back();
			}
			else break;
		} while (v.size() > 1);
		v.push_back(b[i + s].y);
	}
	v.pop_back();
	vector<A>u;
	for (int i = 0; i < v.size(); i++) {
		u.push_back(A{ a[v[i]].x,a[v[i]].y, a[v[i]].t });
	}
	int U = u.size();
	ld res = 0;
	for (int j = 0; j < 2; j++) for (int i = 0; i < U; i++) u.push_back(u[i]);
	for (int i =U; i < 2 * U; i++) {
		ld u1 = atan2(u[i - 1].y - u[i].y, u[i - 1].x - u[i].x), u2 = atan2(u[i + 1].y - u[i].y, u[i + 1].x - u[i].x);
		if (u1 < 0) u1 += 2 * M_PI;
		if (u2 < 0) u2 += 2 * M_PI;
		ld x = abs(u1 - u2);
		if (x > M_PI) x = 2 * M_PI - x;
		d[u[i].t] = M_PI - x;
		res += d[u[i].t];
	}
	for (int i = 0; i < n; i++) {
		printf("%.12LF\n", d[i] / M_PI / 2);
	}
}