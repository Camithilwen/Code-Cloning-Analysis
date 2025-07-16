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
#define pie 3.141592653589793238462643383279
#define int long long
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
int kai(int x, int y, int m) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= m;
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

int comb(int x, int y, int m) {
	if (y > x)return 0;
	return kai(x, y, m) * mod_pow(kai(y, y, m), m - 2, m) % m;
}

int n, m, q;
string s[2010];
int cum1[2010][2010], cum2[2010][2010], cum3[2010][2010];

signed main() {
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)cin >> s[i];
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
		if (s[i][j] == '1')cum1[i][j]++;
		if (i)cum1[i][j] += cum1[i - 1][j];
		if (j)cum1[i][j] += cum1[i][j - 1];
		if (i&&j)cum1[i][j] -= cum1[i - 1][j - 1];
	}
	for (int i = 0; i < n - 1; i++)for (int j = 0; j < m; j++) {
		if (s[i][j] == '1'&&s[i + 1][j] == '1')cum2[i + 1][j]++;
	}
	for (int i = 0; i < n; i++)for (int j = 0; j < m - 1; j++) {
		if (s[i][j] == '1'&&s[i][j + 1] == '1')cum3[i][j + 1]++;
	}
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++) {
		if (i)cum2[i][j] += cum2[i - 1][j];
		if (j)cum2[i][j] += cum2[i][j - 1];
		if (i&&j)cum2[i][j] -= cum2[i - 1][j - 1];
		if (i)cum3[i][j] += cum3[i - 1][j];
		if (j)cum3[i][j] += cum3[i][j - 1];
		if (i&&j)cum3[i][j] -= cum3[i - 1][j - 1];
	}
	for (int i = 0; i < q; i++) {
		int x, y, xx, yy; cin >> x >> y >> xx >> yy; x--; y--; xx--; yy--;
		int p = cum1[xx][yy];
		if (x)p -= cum1[x - 1][yy];
		if (y)p -= cum1[xx][y - 1];
		if (x&&y)p += cum1[x - 1][y - 1];
		int q = cum2[xx][yy] - cum2[x][yy] + cum3[xx][yy] - cum3[xx][y];
		if (y)q -= cum2[xx][y - 1];
		if (y)q += cum2[x][y - 1];
		if (x)q -= cum3[x - 1][yy];
		if (x)q += cum3[x - 1][y];
		cout << p - q << endl;
	}
}