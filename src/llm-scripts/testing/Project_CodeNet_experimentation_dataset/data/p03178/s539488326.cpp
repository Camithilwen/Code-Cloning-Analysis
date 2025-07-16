#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxn = 1e4+3;
int dp[maxn][102][2];
char s[maxn], d;
int main()
{
	scanf("%s %d", s+1, &d);
	int len = strlen(s+1);
	dp[0][0][1] = 1;
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < d; ++j)
			for (int k = 0; k < 10; ++k)
			{
				int to = (j+k)%d;
				if (dp[i][j][1])
				{
					if (k<s[i+1]-'0')
						dp[i+1][to][0] = (dp[i+1][to][0] + dp[i][j][1])%mod;
					else if (k==s[i+1]-'0')
						dp[i+1][to][1] = (dp[i+1][to][1] + dp[i][j][1])%mod;
				}
				if (dp[i][j][0])
					dp[i+1][to][0] = (dp[i+1][to][0] + dp[i][j][0])%mod;
			}
	printf("%d\n", (dp[len][0][1] + dp[len][0][0]-1+mod)%mod);
	return 0;
}