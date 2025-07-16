#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;
const int MOD = (int)1e9 + 7;

int n, l;
int go[N][2];
int dp[2][N];
char s[300000 + 5];

void solve()
{
    n = 8;
    go[0][0] = 2;
    go[0][1] = 3;
    go[1][0] = 4;
    go[1][1] = 5;
    go[2][0] = 0;
    go[2][1] = 0;
    go[3][0] = 0;
    go[3][1] = 1;
    go[4][0] = 6;
    go[4][1] = 1;
    go[5][0] = 5;
    go[5][1] = 5;
    go[6][0] = 4;
    go[6][1] = 4;
    go[7][0] = 0;
    go[7][1] = 1;

    scanf("%s", s);
    l = strlen(s);

    memset(dp, 0, sizeof dp);
    dp[0][7] = 1;
    for(int i = 0; i < l; ++ i) {
        int cur = i & 1;
        int nxt = 1 - cur;
        memset(dp[nxt], 0, sizeof dp[nxt]);

        for(int c = 0; c < 2; ++ c) {
            if (c == 0 && s[i] == '1') continue;
            if (c == 1 && s[i] == '0') continue;

            for(int j = 0; j < n; ++ j) {
                (dp[nxt][go[j][c]] += dp[cur][j]) %= MOD;
            }
        }
    }

    cout << (dp[l & 1][1] + dp[l & 1][5]) % MOD << endl;


}

int main()
{
    solve();
    return 0;
}

