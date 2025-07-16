#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	static const ULL M = 1000000007;

	void Solve() {
		UL N; cin >> N;
		vector<ULL> F(N + 1); F[0] = 1;
		for (UL i = 1; i <= N; i++) F[i] = F[i - 1] * i % M;
		ULL X; cin >> X;
		vector<ULL> S(N); rep(i, N) cin >> S[i];
		sort(S.rbegin(), S.rend());
		vector<ULL> dp(X + 1);
		dp[X] = 1;
		rep(i, N) {
			UL t = N - i;
			vector<ULL> buf(X + 1);
			rep(j, X + 1) {
				if (j < S[i]) buf[j] += dp[j] * t;
				else {
					buf[j % S[i]] += dp[j];
					buf[j] += dp[j] * (t - 1);
				}
			}
			rep(j, X + 1) dp[j] = buf[j] % M;
		}
		ULL ans = 0;
		rep(i, X + 1) ans += dp[i] * i % M;
		ans %= M;
		cout << ans << endl;
	}

	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}