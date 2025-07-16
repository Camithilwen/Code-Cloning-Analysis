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

	Vl dp(X + 1);
	for (int x = 0; x <= X; ++x) dp[x] = x;

	for (int i = 0; i < N; ++i) {
		for (int x = X; x >= 0; --x) {
			dp[x] = (dp[x % S[i]] + i * dp[x]) % MOD;
		}
	}

	cout << dp[X] << endl;
}