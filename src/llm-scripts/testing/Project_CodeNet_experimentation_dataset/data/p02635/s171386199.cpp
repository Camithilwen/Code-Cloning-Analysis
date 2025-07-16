#include <cstdio>
#include <cstring>

using namespace std;

const int mod = 998244353;
char s[301];
int a[300];
int dp[301][301][301][4];

int main() {
    int n, k, i, j, l, r;
    long long ans = 0;
    
    scanf("%s %d", s, &k);
    
    n = strlen(s);
    
    for (i = 0; i < n; i++) a[i] = s[i] - '0';
    
    dp[0][0][0][0] = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (l = 0; l < n && l <= k; l++) {
                for (r = 0; r < 4; r++) {
                    if (dp[i][j][l][r] == 0) continue;
                    
                    if (a[i] == 0) {
                        dp[i + 1][j][l][0] += dp[i][j][l][r];
                        if (dp[i + 1][j][l][0] >= mod) dp[i + 1][j][l][0] -= mod;
                        
                        if (i > 0 && a[i - 1] == 1 && r >= 2) continue;
                        
                        dp[i][j + 1][l + 1][0] += dp[i][j][l][r];
                        if (dp[i][j + 1][l + 1][0] >= mod) dp[i][j + 1][l + 1][0] -= mod;
                    } else {
                        dp[i + 1][j][l][r | 1] += dp[i][j][l][r];
                        if (dp[i + 1][j][l][r | 1] >= mod) dp[i + 1][j][l][r | 1] -= mod;
                        
                        if (j > 0 && (r & 1) == 0) {
                            dp[i + 1][j - 1][l][r | 2] += dp[i][j][l][r];
                            if (dp[i + 1][j - 1][l][r | 2] >= mod) dp[i + 1][j - 1][l][r | 2] -= mod;
                        }
                    }
                }
            }
        }
    }
    
    for (i = 0; i <= k && i <= n; i++) {
        for (j = 0; j < 4; j++) {
            ans += dp[n][0][i][j];
        }
    }
    
    printf("%lld\n", ans % mod);
    
    return 0;
}
