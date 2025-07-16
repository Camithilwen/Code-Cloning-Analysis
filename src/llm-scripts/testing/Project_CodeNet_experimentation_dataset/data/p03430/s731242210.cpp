#include <bits/stdc++.h>
using namespace std;

int main(){
	string s, t;
	int N, K, i, j, k;
	cin >> s;
	scanf("%d", &K);
	N = s.size();
	t = s;
	reverse(t.begin(), t.end());
	char *S = (char *)malloc(sizeof(char) * (N + 1));
	for(i = 1; i <= N; i++){
		S[i] = s[i - 1];
	}
	char *T = (char *)malloc(sizeof(char) * (N + 1));
	for(i = 1; i <= N; i++){
		T[i] = t[i - 1];
	}
	vector<vector<vector<int> > > dp(N + 1, vector<vector<int> >(N + 1, vector<int>(K + 1, 0)));
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]);
			if(S[i] == T[j]){
				dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][0] + 1);
			}
		}
	}
	for(k = 1; k <= K; k++){
		for(i = 1; i <= N; i++){
			for(j = 1; j <= N; j++){
				dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i - 1][j - 1][k - 1] + 1);
				if(S[i] == T[j]){
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + 1);
				}
			}
		}
	}
	int ans = 0;
	for(i = 0; i <= N; i++){
		ans = max(ans, 2 * dp[i][N - i][K]);
	}
	for(i = 1; i <= N; i++){
		ans = max(ans, 2 * dp[i - 1][N - i][K] + 1);
	}
	printf("%d\n", ans);
	return 0;
}