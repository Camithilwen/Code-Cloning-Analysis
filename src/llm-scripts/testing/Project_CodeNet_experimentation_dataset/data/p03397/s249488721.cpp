//%std
#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
const int N = 300003, mod = 1e9 + 7;
void upd (int&a, int b) { a = (a + b) % mod; }
char s[N];
int n, dp[N][3][3];
int main ()
{
	// freopen ("x.in", "r", stdin);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 3; ++j) {//1
			for (int k = 0; k < 3; ++k) {//0
				if (s[i] != '0') {
					if (!k) upd (dp[i][min (j + 1, 2)][k], dp[i - 1][j][k]);
					else upd (dp[i][j][k - 1], dp[i - 1][j][k]);
				}
				if (s[i] != '1') {
					if (k == 2) upd (dp[i][j][1], dp[i - 1][j][k]);
					else upd (dp[i][j][k + 1], dp[i - 1][j][k]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 3; ++i) for (int j = 0; j <= i; ++j) upd (ans, dp[n][i][j]);
	printf ("%d\n", ans);
	// printf ("%d\n", dp[5][0][1]);
	return 0;
}