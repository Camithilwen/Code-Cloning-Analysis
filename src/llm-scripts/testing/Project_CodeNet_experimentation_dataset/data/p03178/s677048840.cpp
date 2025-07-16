#include<bits/stdc++.h>
#define LLI long long int
#define MOD 1000000007
#define de(x) if( x && x == MODE)
#define MODE 0
using namespace std;

char K[100007] = {};
int D;
LLI dp[100007][107] = {};

int main() {
    int i,j;

    scanf("%s", K+1);
    scanf("%d", &D);
    int N = strlen(K+1);
    K[0] = '0';
    int pre = 0;
    for (i=0; i < N; i++) {
        pre += K[i]-'0';
        pre %= D;
        for (j=0; j < (K[i+1]-'0'); j++) {
            dp[i+1][ (pre+j) % D]++;
            dp[i+1][ (pre+j) % D] %= MOD;
        }
        for (j=0; j<D; j++) {
            for (int k=0; k <= 9; k++) {
                dp[i+1][ ( (j + k) % D + D ) % D] += dp[i][j];
                dp[i+1][ ( (j + k) % D + D ) % D] %= MOD;
            }
        }
    }
    pre += K[N]-'0';
    pre %= D;
    dp[N][pre] = ( dp[N][pre] + 1 ) % MOD;
    dp[N][0] = ( dp[N][0] - 1 + MOD) % MOD;

    de(1) {
        for (i=0; i<=N; i++) {
            printf("%d >>> ", i);
            for (j=0; j<D; j++) {
                printf("%lld ", dp[i][j]);
            }
            printf("\n");
        }
    }

    printf("%lld\n", dp[N][0]);

    return 0;
}
