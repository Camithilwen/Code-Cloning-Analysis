#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

const ll mod = 1000000007;


int main() {
	ll n;
	cin >> n;
	vector<vector<ll>> scores(n, vector<ll>(n));
	rep(i, n) {
		rep(j, n) {
			cin >> scores[i][j];
		}
	}
	vector<ll> dp(1LL << n, 0);
	rep(i, 1LL << n) {
		ll add = 0;
		for (ll j = 0; j < n; j++) {
			for (ll k = 0; k < j; k++) {
				if (i & (1LL << j)) {
					if (i & (1LL << k)) {
						dp[i] += scores[j][k];
					}
				}
			}
		}
	}
	for (ll i = 0; i < 1LL << n;i++) {
		ll u = dp[i];
		for (ll j = i; j > 0; j = ((j-1) & i)) {
			u = max(u, dp[j] + dp[(i ^ j)]);
		}
		dp[i] = u;
	}
	cout << dp[(1LL << n) - 1] << endl;
	return 0;
}
