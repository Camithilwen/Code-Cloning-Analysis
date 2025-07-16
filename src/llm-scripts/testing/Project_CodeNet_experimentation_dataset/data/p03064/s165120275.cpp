#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
const ll MOD = 998244353;
void add(ll& x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
}
void sub(ll& x, ll y) {
	x -= y;
	if (x < 0) x += MOD;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<ll> ndp(90001), dp(90001);
	vector<ll> ndp2(90001), dp2(90001);
	dp[0] = dp2[0] = 1;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		int a; 
		scanf("%d", &a);
		sum += a;
		fill(ndp.begin(), ndp.end(), 0);
		fill(ndp2.begin(), ndp2.end(), 0);
		for (int s = 0; s <= i * 300; ++s) {
			add(ndp[s], dp[s]);
			add(ndp[s], dp[s]);
			add(ndp[s + a], dp[s]);
			add(ndp2[s], dp2[s]);
			add(ndp2[s + a], dp2[s]);
		}
//		for (int s = 0; s <= 10; ++s) db2(s, ndp[s]);
		swap(dp, ndp);
		swap(dp2, ndp2);
	}
	ll ans = 1;
	for (int i = 1; i <= n; ++i) ans = ans * 3 % MOD;
	for (int i = (sum + 1) / 2; i <= sum; ++i) {
//		db2(i, dp[i]);
		sub(ans, dp[i] * 3 % MOD);
	}
	if (sum % 2 == 0) {
		add(ans, dp2[sum / 2] * 3 % MOD);
	}
	printf("%lld\n", ans);
}
