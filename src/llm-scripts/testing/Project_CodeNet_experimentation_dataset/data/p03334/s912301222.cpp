#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <random>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#define debug(x) cerr << #x << ':' << x << '\n'
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef complex<ld> com;
constexpr int inf = 1000000010;
constexpr ll INF = 1000000000000000010;
constexpr ld eps = 1e-12;
constexpr ld pi = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	n *= 2;
	vector<vector<int>> a(n, vector<int>(n));
	for (int z = 1; z <= 2; z++) {
		int d;
		cin >> d;
		int sz = 1;
		while (d % 4 == 0) {
			d >>= 2; sz <<= 1;
		}
		if (d % 4 == 1) rep(i, n) rep(j, n) if (i % (2 * sz) < sz && j % (2 * sz) < sz || i % (2 * sz) >= sz && j % (2 * sz) >= sz) a[i][j] += z;
		if (d % 4 == 2) rep(i, n) rep(j, n) if (i % (2 * sz) < sz) a[i][j] += z;
	}
	vector<int> cnt(4);
	rep(i, n) rep(j, n) cnt[a[i][j]]++;
	int tmp = 0; int use = 0;
	rep(i, 4) if (chmax(tmp, cnt[i])) use = i;
	int q = n * n / 4;
	rep(i, n) {
		rep(j, n) {
			if (q == 0) break;
			if (a[i][j] == use) {
				cout << i << ' ' << j << '\n';
				q--;
			}
		}
	}
}