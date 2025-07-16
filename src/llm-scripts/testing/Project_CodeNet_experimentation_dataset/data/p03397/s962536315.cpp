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
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
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
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;

string s; int n;
ll dp[1 << 18][8];

ll mod_pow(ll x, ll n) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return res;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> s; n = s.length(); int d = (n - 3) / 2;
	if (n == 1) {
		if (s[0] == '0')cout << 0 << endl;
		else cout << 1 << endl;
		return 0;
	}
	int num = 0;
	rep(i, n) {
		if (s[i] == '?')num++;
	}
	int cnt = 0;
	rep(i, 8) {
		bool valid = true;
		rep(j, 3) {
			int t = 0;
			if (i&(1 << j))t = 1;
			if (t == 0 && s[2-j] == '1')valid = false;
			if (t == 1 && s[2-j] == '0')valid = false;
		}
		if (valid)dp[0][i] = 1;
	}
	ll ans = 0;
	rep(i, 3) {
		if (s[i] == '?')cnt++;
	}
	rep(i, d) {
		ans = (ans + dp[i][6] * mod_pow(2, num - cnt) % mod + dp[i][7] * mod_pow(2, num - cnt) % mod) % mod;
		char le = s[2 * i + 3], ri = s[2 * i + 4];
		vector<int> v;
		if (le != '1'&&ri != '1')v.push_back(0);
		if (le != '1'&&ri != '0')v.push_back(1);
		if (le != '0'&&ri != '1')v.push_back(2);
		if (le != '0'&&ri != '0')v.push_back(3);
		int len = v.size();
		rep(j, len) {
			dp[i + 1][v[j]] = (dp[i + 1][v[j]] + dp[i][0] + dp[i][1]+dp[i][2]) % mod;
			dp[i + 1][v[j] + 4] = (dp[i + 1][v[j] + 4] + dp[i][3] + dp[i][5]) % mod;
			dp[i + 1][4 + v[j] % 2] = (dp[i + 1][4 + v[j] % 2] + dp[i][4]) % mod;
		}
		if (le == '?')cnt++;
		if (ri == '?')cnt++;
	}
	ans = (ans + dp[d][3] + dp[d][5] + dp[d][6] + dp[d][7]) % mod;
	cout << ans << endl;
	//stop
	return 0;
}