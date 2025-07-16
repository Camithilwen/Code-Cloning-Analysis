#include <cstdio>
#include <cstring>

using namespace std;

char s[300001];
long long b[300001];
int c[300001];
long long dp[2][3];

bool can(int x, int c) {
    return (s[x] == '?') || (s[x] == '0' + c);
}

int main() {
    int n, m = 1000000007, i, j, k, l;
    long long ans = 0;
    
    scanf("%s", s);
    
    n = strlen(s);
    
    b[0] = 1;
    for (i = 1; i <= n; i++) b[i] = b[i - 1] * 2 % m;
    
    for (i = n - 1; i >= 0; i--) {
        c[i] = c[i + 1];
        if (s[i] == '?') c[i]++;
    }
    
    for (i = 0; i < 2; i++) {
        if (can(0, i)) dp[0][i]++;
    }
    
    for (i = 1; i < n; i += 2) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                if (!can(i, j) || !can(i + 1, k)) continue;
                
                for (l = 0; l < 3; l++) {
                    long long x = dp[0][l];
                    
                    if (x == 0) continue;
                    
                    if (l == 0) {
                        if (j == 1 && k == 1) {
                            dp[1][1] += x;
                            if (dp[1][1] >= m) dp[1][1] -= m;
                        } else {
                            dp[1][0] += x;
                            if (dp[1][0] >= m) dp[1][0] -= m;
                        }
                    } else if (l == 1) {
                        if (j == 1) {
                            ans += x * b[c[i + 2]] % m;
                            if (ans >= m) ans -= m;
                        } else if (j == 0 && k == 0) {
                            dp[1][2] += x;
                            if (dp[1][2] >= m) dp[1][2] -= m;
                        } else {
                            dp[1][1] += x;
                            if (dp[1][1] >= m) dp[1][1] -= m;
                        }
                    } else {
                        if (k == 0) {
                            dp[1][2] += x;
                            if (dp[1][2] >= m) dp[1][2] -= m;
                        } else {
                            dp[1][1] += x;
                            if (dp[1][1] >= m) dp[1][1] -= m;
                        }
                    }
                }
            }
        }
        
        for (j = 0; j < 3; j++) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }
    
    printf("%lld\n", (ans + dp[0][1]) % m);
    
    return 0;
}
