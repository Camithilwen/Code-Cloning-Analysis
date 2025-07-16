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
#include <random>
#include <string.h>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 1145141919810364364
#define int long long
#define all(vec) vec.begin(),vec.end()
#define P pair<int,int>

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
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

int n, a[20][20];
int d[(1 << 16)];
vector<int> vec;

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> a[i][j];
	for (int i = 1; i < (1 << n); i++) {
		vec.clear();
		for (int j = 0; j < n; j++)if (i&(1 << j))vec.push_back(j);
		int m = (int)vec.size();
		int ma = 0;
		for (int j = 0; j < (int)vec.size(); j++)for (int k = j + 1; k < (int)vec.size(); k++)ma += a[vec[j]][vec[k]];
		for (int j = 0; j < (1 << m); j++) {
			int cnt = 0;
			for (int k = 0; k < m; k++)if (j&(1 << k))cnt += (1 << vec[k]);
			ma = max(ma, d[cnt] + d[i - cnt]);
		}
		d[i] = ma;
	}
	cout << d[(1 << n) - 1] << endl;
}