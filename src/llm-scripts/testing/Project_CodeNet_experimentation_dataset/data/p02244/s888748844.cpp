#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#include <new>
#include <sstream>
#include <complex>
#define BIT(nr) (1ULL << (nr))
#define int long long
#define ll long long
#define double complex<long double>
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	
#define LL_HALFMAX 9223372036854775807 / 2	
#define MIN -(9223372036854775807 / 2)
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }

using namespace std;

int G[15][15];

signed main() {
	map<int, int> x, y, d1, d2;
	// d1: 和が一定 d2: 差が一定
	int k;
	cin >> k;
	vector<string> ans(8, "........"), fans(8, "........");
	rep(i, k) {
		int r, c;
		cin >> r >> c;
		ans[r][c] = 'Q';

		y[r] = 1;
		x[c] = 1;
		d1[r + c] = 1;
		d2[c - r] = 1;
	}

	function<void(int)> dfs = [&](int xPos) {
		if (xPos == 8) {
			fans = ans;
			return;
		}
		// 既に置いてあったらNG
		if (x[xPos] == 1) {
			dfs(xPos+1);
		}

		rep(yPos, 8) {
			if (y[yPos] == 1) {
				continue;
			}
			if (d1[xPos + yPos] == 1) {
				continue;
			}
			if (d2[xPos - yPos] == 1) {
				continue;
			}

			y[yPos] = 1;
			d1[xPos + yPos] = 1;
			d2[xPos - yPos] = 1;
			ans[yPos][xPos] = 'Q';

			dfs(xPos + 1);

			y[yPos] = 0;
			d1[xPos + yPos] = 0;
			d2[xPos - yPos] = 0;
			ans[yPos][xPos] = '.';
		}
	};

	dfs(0);

	rep(i, 8) {
		cout << fans[i] << "\n";
	}

	return 0;
}
