// IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cerr << ends << H; debug_out(T...); }
#define debug(...) cerr << "{" << #__VA_ARGS__ << "}:", debug_out(__VA_ARGS__)
typedef long long ll;
typedef pair<int, int> pii;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;

////////////////////////////////////////////////////////////////////

const int N = 2e3 + 5, M = 4e6 + 5;

int DP[N][N], F[M], I[M];

int Power(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = 1LL * a * a % MOD) if (b & 1) res = 1LL * res * a % MOD;
	return res;
}
int C(int n, int r) { return r > n ? 0 : 1LL * I[r] * I[n - r] % MOD * F[n] % MOD; }

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	F[0] = 1;
	for (int i = 1; i < M; i++) F[i] = 1LL * i * F[i - 1] % MOD;
	I[M - 1] = Power(F[M - 1], MOD - 2);
	for (int i = M - 2; i >= 0; i--) I[i] = 1LL * (i + 1) * I[i + 1] % MOD;
	
	int n, k; cin >> n >> k;
	if (k == 1) die(1);
	DP[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		DP[i][0] = 1LL * DP[i - 1][0] * C(i * (k - 1) - 1, k - 2) % MOD;
		for (int j = 1; j <= i; j++) DP[i][j] = (DP[i][j - 1] + 1LL * DP[i - 1][j] * C(i * (k - 1) + j - 1, k - 2) % MOD) % MOD;
	}
	cout << 1LL * DP[n][n] * F[n] % MOD << endl;

	return 0;
}
