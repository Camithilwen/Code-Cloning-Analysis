#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
ll dp[200][100001];
int S[200];
int main() {
	int N, X;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	sort(S, S + N);
	for (int i = 0; i <= X; i++) {
		dp[0][i] = i % S[0];
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= X; j++) {
			(dp[i][j] += dp[i - 1][j%S[i]]) %= MOD;
			(dp[i][j] += (i*dp[i - 1][j]) % MOD) %= MOD;
		}
	}
	cout << dp[N - 1][X] << endl;
}
