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
#include <functional>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <unordered_map>
#include <cstdio>
#include <climits>
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

string s, t;
int k;
int d[310][310][310];

signed main() {
	std::random_device rnd;
	std::mt19937_64 mt(rnd());
	cin >> s >> k;
	t = s;
	reverse(all(t));
	int n = (int)s.size();
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
		if (n <= i + j)continue;
		for (int l = 0; l <= k; l++)d[i + 1][j + 1][l] = max(d[i][j + 1][l], d[i + 1][j][l]);
		if (s[i] == t[j])for (int l = 0; l <= k; l++)d[i + 1][j + 1][l] = max(d[i + 1][j + 1][l], d[i][j][l] + 1);
		else for (int l = 0; l < k; l++)d[i + 1][j + 1][l + 1] = max(d[i + 1][j + 1][l + 1], d[i][j][l] + 1);
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)for (int j = 0; j <= n; j++) {
		if (n <= i + j - 2)continue;
		int ma = 0;
		for (int l = 0; l <= k; l++)ma = max(ma, d[i][j][l]);
		if (i + j == n + 1)ans = max(ans, 2 * ma - 1);
		else ans = max(ans, 2 * ma);
	}
	cout << ans << endl;
}
