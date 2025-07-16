#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919364364
#define int long long
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>
#define S second
#define F first

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}

int n;
string s;
bool bl[200010];
int cnt1, cnt2;
int cnt;
int ans = 1;

signed main() {
	cin >> n >> s;
	bl[0] = 0;
	cnt2++;
	for (int i = 1; i < 2 * n; i++) {
		if (s[i - 1] == s[i]) {
			if (bl[i - 1])bl[i] = false;
			else bl[i] = true;
		}
		else bl[i] = bl[i - 1];
		if (bl[i])cnt1++;
		else cnt2++;
	}
	if (s[0] == 'W' || s[2 * n - 1] == 'W' || cnt1 != cnt2) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < 2 * n; i++) {
		if (!bl[i])cnt++;
		else {
			ans *= cnt;
			ans %= mod;
			cnt--;
		}
	}
	ans *= kai(n, n);
	ans %= mod;
	cout << ans << endl;
}