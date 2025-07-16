#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef vector<int> Vi;
typedef vector<lli> Vl;
typedef pair<int, int> Pii;
typedef pair<lli, lli> Pll;


//===

const int MOD = (int)1e9 + 7;


int main()
{
	int N, X;
	cin >> N >> X;
	vector<int> S(N);
	for (int i = 0; i < N; ++i) cin >> S[i];

	sort(S.begin(), S.end());

	vector<Vl> dp(N + 1, Vl(X + 1));
	for (int x = 0; x <= X; ++x) dp[0][x] = x;

	for (int i = 0; i < N; ++i) {
		for (int x = 0; x <= X; ++x) {
			dp[i + 1][x] = (dp[i][x % S[i]] + i * dp[i][x]) % MOD;
		}
	}

	cout << dp[N][X] << endl;
}