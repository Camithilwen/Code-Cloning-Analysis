#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		string S; cin >> S;
		string rS = S; reverse(rS.begin(), rS.end());
		ULL ans = 0;
		rep(i, (1 << N)) {
			string R, B;
			rep(j, N) { if (i & (1 << j)) R.push_back(S[j]); else B.push_back(S[j]); }
			R.push_back(' '); B.push_back(' ');
			UL dp[19][19] = {};
			dp[0][0] = 1;
			rep(b, B.size()) {
				rep(r, R.size()) {
					if (B[b] == rS[r + b]) dp[r][b + 1] += dp[r][b];
					if (R[r] == rS[r + b]) dp[r + 1][b] += dp[r][b];
				}
			}
			ans += dp[R.size() - 1][B.size() - 1];
		}
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