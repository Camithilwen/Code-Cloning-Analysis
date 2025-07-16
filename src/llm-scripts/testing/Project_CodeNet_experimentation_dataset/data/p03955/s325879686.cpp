#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
using namespace std;
typedef unsigned long long ll;
typedef unsigned int ui;
const ll mod = (ll)(1e+9) + 7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-12;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
ll bit[1 << 17][2]; int n;
void add(int id,int a, ll w) {
	for (int i = a; i <= n + 1; i += i & -i)bit[i][id] += w;
}
ll sum(int id,int a) {
	ll ret = 0;
	for (int i = a; i > 0; i -= i & -i)ret += bit[i][id];
	return ret;
}
int a[1 << 17][3];
P b[1 << 17];
int main() {
	cin >> n;
	rep(i, 3) {
		rep(j, n) {
			cin >> a[j][i]; a[j][i]--;
		}
	}
	bool f = true;
	rep(i, n) {
		int key = a[i][0]/3;
		rep1(j, 2) {
			if (key != a[i][j] / 3)f = false;
		}
		if (a[i][1] == a[i][0] + 1 && a[i][2] == a[i][0] + 2) {
			b[key] = { i+1,0 };
		}
		else if (a[i][1] == a[i][0] - 1 && a[i][2] == a[i][0] - 2) {
			b[key] = { i+1,1 };
		}
		else f = false;
		if (i % 2 != key % 2)f = false;
		//cout << key << endl;
	}
	if (!f) {
		cout << "No" << endl;
	}
	else {
		ll cnt[2] = {};
		rep(i, n) {
			int k = i % 2;
			cnt[k ^ 1] += b[i].second;
			cnt[k] += (b[i].first-1)/2 - sum(k,b[i].first);
			add(k,b[i].first,1);
			//cout << cnt << endl;
		}
		//cout << cnt[0] << " " << cnt[1] << endl;
		if (cnt[0]% 2==0&&cnt[1]%2==0)cout << "Yes" << endl;
		else cout << "No" << endl;
		//cout << cnt << endl;
	}
	return 0;
}
