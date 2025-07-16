#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
//const long long MOD = 1000000007;
//const long long MOD = 998244353;
long long MOD;

using namespace std;

ll dp[6010][8005];

void solve()
{
    int n;
    scanf("%d%lld", &n, &MOD);

    dp[0][n] = 1;   // dp[i][j]: 後ろからi文字目まで選択済で、ただし残る2マス数が残る1マス数よりj-n個多い場合の数
    int i, j;
    for (i = 0; i < n * 3; i++) {
        for (j = 0; j <= n*4; j++) {
            if (dp[i][j]) {
                if(j+1<=n*4) dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
                if(i+2<=n*3 && j-1>=0)   dp[i + 2][j - 1] = (dp[i + 2][j - 1] + dp[i][j] * (n*3-i-1) % MOD) % MOD;
                if(i+3<=n*3) dp[i + 3][j] = (dp[i + 3][j] + dp[i][j] * (n * 3 - i - 1) % MOD * (n * 3 - i - 2) % MOD) % MOD;            
            }
        }
    }
    ll ans = 0;
    for (j = n; j <= n * 4; j++) {
        ans = (ans + dp[n * 3][j]) %MOD;
    }
    printf("%lld\n", ans);

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
