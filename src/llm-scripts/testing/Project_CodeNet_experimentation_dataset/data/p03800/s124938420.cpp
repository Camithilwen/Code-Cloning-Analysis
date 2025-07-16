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

	int n;
	string s;
	cin >> n >> s;
	rep(i, 4) {
		string t = "";
		rep(j, 2) {
			if ((i >> j) & 1) t += 'S';
			else t += 'W';
		}
		for (int i = 1; i < n - 1; i++) {
			int cnt = 0;
			if (t[i - 1] == 'S') cnt ^= 1;
			if (t[i] == 'S') cnt ^= 1;
			if (s[i] == 'o') cnt ^= 1;
			if (cnt) t += 'S';
			else t += 'W';
		}
		int check = 0;
		if (t[n - 2] == 'S') check ^= 1;
		if (t[n - 1] == 'S') check ^= 1;
		if (t[0] == 'S') check ^= 1;
		if (s[n - 1] == 'o') check ^= 1;
		if (check) continue;
		if (t[n - 1] == 'S') check ^= 1;
		if (t[0] == 'S') check ^= 1;
		if (t[1] == 'S') check ^= 1;
		if (s[0] == 'o') check ^= 1;
		if (check) continue;
		cout << t << '\n';
		return 0;
	}
	cout << -1 << '\n';
}