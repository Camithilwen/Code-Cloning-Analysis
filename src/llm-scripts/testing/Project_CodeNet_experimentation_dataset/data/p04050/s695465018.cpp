#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define int long long
#define ll long long
#define P pair<int,int>
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define all(V) V.begin(),V.end()
#ifdef int
constexpr int INF = LLONG_MAX / 10;
#else
constexpr int INF = INT_MAX / 10;
#endif
constexpr double eps = 1e-9;
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
using namespace std;
inline ll gcd(ll a, ll b) {
	while (b) {
		ll c = a;
		a = b; b = c % b;
	}
	return a;
}
inline ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
bool isprime(ll n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
ll mypow(ll a, ll b) {
	if (!b)return 1;
	if (b & 1)return mypow(a, b - 1) * a;
	int memo = mypow(a, b >> 1);
	return memo * memo;
}
int n, m, a[110];
signed main() {
	cin >> n >> m;
	int oddcount = 0;
	rep(i, m) {
		cin >> a[i];
		if (a[i] & 1)oddcount++;
	}
	if (m == 1) {
		if (a[0] == 1) {
			cout << 1 << endl << 1 << endl << 1 << endl;
			return 0;
		}
		cout << a[0] << endl;
		cout << 2 << endl;
		cout << a[0] - 1 << " " << 1 << endl;
		return 0;
	}
	if (oddcount >= 3) {
		puts("Impossible");
		return 0;
	}
	if (oddcount == 2 && (n & 1)) {
		puts("Impossible");
		return 0;
	}
	REP(i, m - 1) {
		if (a[i] & 1) {
			if (a[0] & 1) {
				swap(a[i], a[m - 1]);
				break;
			}
			swap(a[0], a[i]);
		}
	}
	rep(i, m - 1)cout << a[i] << " ";
	cout << a[m - 1] << endl;
	if (a[0] != 1) {
		cout << m << endl;
		cout << a[0] - 1 << " ";
	}
	else cout << m - 1 << endl;
	REP(i, m - 2)cout << a[i] << " ";
	cout << a[m - 1] + 1 << endl;
	return 0;
}