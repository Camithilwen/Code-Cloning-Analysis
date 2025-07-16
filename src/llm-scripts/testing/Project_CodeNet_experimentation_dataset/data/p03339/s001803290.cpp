#include "bits/stdc++.h"
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const long long INF = 100000000;
int dp[300100][2];


int main()
{

	int N; cin >> N;
	string S; cin >> S;
	dp[0][0] = 0;
	dp[0][1] = 0;
	for (int i = 1; i < N; i++) if (S.at(i) == 'E') dp[0][1]++;
	for (int i = 0; i < N-1; i++) {
		if (S.at(i) == 'E') dp[i + 1][0] = dp[i][0];
		else dp[i + 1][0] = dp[i][0] + 1;
		if (S.at(i+1) == 'E') dp[i + 1][1] = dp[i][1] - 1;
		else dp[i + 1][1] = dp[i][1];
	}
	
	int ans = INF;
	for (int i = 0; i < N; i++) chmin(ans, dp[i][0] + dp[i][1]);

	cout << ans << endl;
	return 0;
}
