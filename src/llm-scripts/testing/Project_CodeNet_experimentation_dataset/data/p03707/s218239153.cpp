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
//#define int long long
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n, m, q;
	cin >> n >> m >> q;
	vector<string> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<int>> sum(n + 1, vector<int>(m + 1));
	vector<vector<int>> sum2(n + 1, vector<int>(m + 1));
	vector<vector<int>> sum3(n + 1, vector<int>(m + 1));
	rep(i, n) {
		rep(j, m) {
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
			sum2[i + 1][j + 1] = sum2[i + 1][j] + sum2[i][j + 1] - sum2[i][j];
			sum3[i + 1][j + 1] = sum3[i + 1][j] + sum3[i][j + 1] - sum3[i][j];
			if (a[i][j] == '1') sum[i + 1][j + 1]++;
			if (i != 0 && a[i - 1][j] == '1'&&a[i][j] == '1') sum2[i + 1][j + 1]++;
			if (j != 0 && a[i][j - 1] == '1'&&a[i][j] == '1') sum3[i + 1][j + 1]++;
		}
	}
	rep(_, q) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--;
		int ans = sum[x1][y1] + sum[x2][y2] - sum[x1][y2] - sum[x2][y1];
		ans -= sum2[x1 + 1][y1] + sum2[x2][y2] - sum2[x1 + 1][y2] - sum2[x2][y1];
		ans -= sum3[x1][y1 + 1] + sum3[x2][y2] - sum3[x1][y2] - sum3[x2][y1 + 1];
		cout << ans << '\n';
	}
} 