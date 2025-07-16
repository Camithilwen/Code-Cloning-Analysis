#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <cmath>
#include <unordered_map>
#include <cstdio>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long ll;

ll gcd(ll x, ll y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y)*y;
}
ll kai(ll x, ll y, ll m) {
	ll res = 1;
	for (ll i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
	}
	return res;
}
ll mod_pow(ll x, ll y, ll m) {
	ll res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

ll comb(ll x, ll y, ll m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

const ll mod = 1000000007;

int n, x;
vector<int> vec[1050000];
ll d[500010];
ll ans;

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		x ^= a;
		vec[x].push_back(i);
	}
	if (x) {
		ll cnt1 = 0, cnt2 = 1;
		for (int j = 0; j < (int)vec[x].size(); j++) {
			int p = 0;
			if (j)p = vec[x][j - 1];
			int t = lower_bound(all(vec[0]), vec[x][j]) - lower_bound(all(vec[0]), p);
			cnt2 = (cnt2 + cnt1 * t) % mod;
			cnt1 = (cnt1 + cnt2) % mod;
		}
		cout << cnt2 << endl;
		return 0;
	}
	for (int i = 1; i < (1 << 20); i++) {
		if ((int)vec[i].size() == 0)continue;
		ll cnt1 = 0, cnt2 = 1;
		for (int j = 0; j < (int)vec[i].size(); j++) {
			int p = 0;
			if (j)p = vec[i][j - 1];
			int t = lower_bound(all(vec[0]), vec[i][j]) - lower_bound(all(vec[0]), p);
			cnt2 = (cnt2 + cnt1 * t) % mod;
			cnt1 = (cnt1 + cnt2) % mod;
		}
		ans = (ans + cnt1) % mod;
	}
	ll cnt = 1;
	for (int i = 1; i < (int)vec[0].size(); i++)cnt = cnt * 2 % mod;
	cout << (ans + cnt) % mod << endl;
}
