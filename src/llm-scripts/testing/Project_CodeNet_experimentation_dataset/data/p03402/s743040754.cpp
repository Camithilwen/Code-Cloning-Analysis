//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define all(x) (x).begin(),(x).end()

#define MOD 1000000007LL
#define INF (1LL<<60LL)
#define int long long
#define MAX_N (100001)
typedef long long ll;

using namespace std;


vector<vector<bool>> v(100, vector<bool>(100,1));



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b; cin >> a >> b;
	bool rev = false;
	if (a > b) {
		swap(a, b);
		rev = true;
	}
	int i = 0, j = 0;
	if (b > 1)a--;
	rep(_, a) {
		v[i][j] = 0;
		j += 2;
		if (j >= 100) {
			i++;
			j = i % 2;
		}
	}
	b -= max(0LL, a - 50);
	i += 3;
	j = 1;
	rep(_, b-1) {
		rep(i2, 3)rep(j2, 3) {
			v[i + i2 - 1][j + j2 - 1] = 0;
		}
		v[i][j] = 1;
		j += 2;
		if (j >= 98) {
			i+=2;
			j = 1;
		}
	}
	char m[2];
	if (!rev) {
		m[0] = '.';
		m[1] = '#';
	}else  {
		m[1] = '.';
		m[0] = '#';
	}
	cout << 100 << " " << 100 << "\n";
	rep(i2, 100)rep(j2, 100) {
		cout << m[v[i2][j2]];
		if (j2 == 99) cout << "\n";
	}
}