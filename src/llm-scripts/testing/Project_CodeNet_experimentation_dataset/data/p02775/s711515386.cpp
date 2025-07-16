#include<bits/stdc++.h>
using namespace std;
int const nax = 1e6 + 10;
char s[nax];
int n;
int dp[nax][2];
int d;


int main () {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    s[0] = '0';

    dp[n + 1][1] = 1;

    for (int i = n ; i >= 0 ; -- i) {
        d = s[i] - '0';
        dp[i][0] = min(dp[i + 1][1] + 10 - d, dp[i + 1][0] + d);
        dp[i][1] = min(dp[i + 1][0] + d + 1, dp[i + 1][1] + 9 - d);
    }

    printf("%d\n", dp[0][0]);
}
