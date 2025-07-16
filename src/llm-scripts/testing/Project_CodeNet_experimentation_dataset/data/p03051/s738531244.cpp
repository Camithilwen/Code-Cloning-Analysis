#include "bits//stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#define ALL(v) v.begin(), v.end()
typedef pair<int, int> P;
ll mod_pow(ll a, ll n) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		ll tmp = mod_pow(a, n / 2);
		return (tmp * tmp) % MOD;
	}
	return (a * mod_pow(a, n - 1)) % MOD;
}

int A[500001];
int zero[500001];
int pre[1 << 20];
vector<P> v[1 << 20];
ll dp[500001][2];
void solve(int k) {
	for (int i = 0; i <= v[k].size(); i++) dp[i][0] = dp[i][1] = 0;
	dp[1][0] = 1;
	for (int i = 1; i < v[k].size(); i++) {
		dp[i + 1][0] = dp[i][0];
		dp[i + 1][1] = dp[i][1];
		if (v[k][i].first == 0) {
			(dp[i + 1][0] += dp[i][1] * v[k][i].second) %= MOD;
		}
		else {
			(dp[i + 1][1] += dp[i][0] * v[k][i].second) %= MOD;
		}
	}
	return;
}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) A[i] ^= A[i - 1];
	memset(pre, -1, sizeof(pre));
	zero[0] = 1;
	for (int i = 1; i <= N; i++) {
		zero[i] = zero[i - 1];
		if (A[i] != 0) {
			int cnt = zero[i];
			if (pre[A[i]] != -1) cnt -= zero[pre[A[i]]];
			if (cnt > 0) v[A[i]].emplace_back(0, cnt);
			v[A[i]].emplace_back(A[i], 1);
			pre[A[i]] = i;
		}
		else {
			zero[i]++;
		}
	}
	for (int i = 1; i < (1 << 20); i++) {
		if (pre[i] == -1) continue;
		int cnt = zero[N];
		cnt -= zero[pre[i]];
		if (cnt > 0) v[i].emplace_back(0, cnt);
	}
	int X = A[N];
	if (X != 0) {
		solve(X);
		cout << dp[v[X].size() - 1][0] << endl;
		return 0;
	}
	ll ans = 0;
	for (int i = 1; i < (1 << 20); i++) {
		if (v[i].empty()) continue;
		solve(i);
		(ans += dp[v[i].size() - 1][1]) %= MOD;
	}
	(ans += mod_pow(2, zero[N] - 2)) %= MOD;
	cout << ans << endl;
}
