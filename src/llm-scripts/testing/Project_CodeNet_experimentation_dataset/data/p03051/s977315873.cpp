#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pii;

const ll MAX_N = 6e5 + 25, MAX_M = 1500000, MOD = 1e9 + 7;
ll n, ans;
ll Arr[MAX_N];
ll dp[MAX_N];
ll DP[MAX_N];
ll ind;
vector <ll> vec[MAX_N];
vector <pii> P[MAX_M];
unordered_map <ll, ll> Map;

ll _sum (ll a, ll b) {
	ll c = a + b;
	if (MOD <= c)
		c -= MOD;

	return c;
}

ll _mul (ll a, ll b) {
	ll c = 1LL * a * b % MOD;
	return c;
}

ll _pow (ll a, ll b) {
	if (!b)
		return 1;

	ll res = _pow(a, b >> 1);
	res = _mul(res, res);

	if (b & 1)
		res = _mul(res, a);

	return res;
}

void solve1(ll tmp) {
	ll a = 1, b = 0, x = 0;
	for (ll i = 0; i < n; i++) {
		x ^= Arr[i];

		if (x != 0 && x != tmp)
			continue;

		if (x == 0) {
			dp[i] = b;
			a = _sum(a, dp[i]);
		}
		else {
			dp[i] = a;
			b = _sum(b, dp[i]);
		}
	}

	cout << dp[n - 1] << "\n";
}

ll calc1() {
	ll x = 0, cnt = 0;
	for (ll i = 0; i < n; i++) {
		x ^= Arr[i];
		if (!x)
			cnt++;
	}

	return _pow(2, cnt - 1);
}

ll calc2(ll tmp) {
	ll res = P[tmp][0].second;
	DP[0] = 0;
	dp[0] = P[tmp][0].second;

	for (ll i = 1; i < P[tmp].size(); i++) {
		dp[i] = _mul(_mul(dp[i - 1], P[tmp][i].second), P[tmp][i].first - P[tmp][i - 1].first);
		ll f = _mul(dp[i - 1], _pow(P[tmp][i - 1].second, MOD - 2));
		f = _sum(f, _mul(P[tmp][i].first - P[tmp][i - 1].first, DP[i - 1]));
		dp[i] = _sum(dp[i], _mul(f, P[tmp][i].second));

		DP[i] = _sum(DP[i - 1], dp[i - 1]);
		res = _sum(res, dp[i]);
	}

	return res;
}

void process1() {
	ll x = 0;
	for (ll i = 0; i < n; i++) {
		vec[ind].push_back(Arr[i]);
		x ^= Arr[i];
		if (!x)
			ind++;
	}
}

void process2() {
	for (ll i = 0; i < ind; i++) {
		Map.clear();
		ll x = 0;
		for (ll j = 0; j + 1 < vec[i].size(); j++) {
			x ^= vec[i][j];
			Map[x]++;
		}

		for (auto t: Map)
			P[t.first].push_back({i, t.second});
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> Arr[i];

	ll tmp = 0;
	for (ll i = 0; i < n; i++)
		tmp ^= Arr[i];

	if (tmp) {
		solve1(tmp);
		return 0;
	}

	ans = calc1();
	process1();
	process2();

	for (ll i = 0; i < MAX_M; i++)
		if (P[i].size())
			ans = _sum(ans, calc2(i));

	cout << ans << "\n";
	return 0;
}
