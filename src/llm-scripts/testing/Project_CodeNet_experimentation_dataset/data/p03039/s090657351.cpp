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

const int N = 2e5 + 5;

int F[N], I[N];

int P(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = 1LL * a * a % MOD) if (b & 1) res = 1LL * res * a % MOD;
	return res;

}
int C(int n, int r) { return r > n ? 0 : 1LL * I[r] * I[n - r] % MOD * F[n] % MOD; }

int main() {

	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	F[0] = 1;
	for (int i = 1; i < N; i++) F[i] = 1LL * F[i - 1] * i % MOD;
	I[N - 1] = P(F[N - 1], MOD - 2);
	for (int i = N - 2; i >= 0; i--) I[i] = 1LL * I[i + 1] * (i + 1) % MOD;

	int n, m, k; cin >> n >> m >> k;
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = (ans + 1LL * i * (n - i) % MOD * m % MOD * m % MOD) % MOD;
	for (int i = 1; i <= m; i++) ans = (ans + 1LL * i * (m - i) % MOD * n % MOD * n % MOD) % MOD;
	cout << 1LL * ans * C(n * m - 2, k - 2) % MOD << endl;

	return 0;
}
