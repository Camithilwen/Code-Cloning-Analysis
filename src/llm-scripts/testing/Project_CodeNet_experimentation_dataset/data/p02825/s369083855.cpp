#include <bits/stdc++.h>
using namespace std;

int dp[1005];

const char domino[15][15][15] = {
    {}, // 0
    {}, // 1
    {}, // 2
    {}, // 3
    {"aacd", "bbcd", "efgg", "efhh"}, // 4
    {"aabbc", "dee.c", "d..fg", "j..fg", "jiihh"}, // 5
    {}, // 6
    {"aabbcc.", "dd.ee.f", "..h..gf", "..h..gm", "ii.jj.m", "..k..ln", "..k..ln"} // 7
};

char ans[1005][1005];

int main(){
    int N;
    scanf("%d", &N);
    memset(ans, 0, sizeof(ans));
    if(N < 3){printf("-1"); return 0;}
    if(N == 3){
        printf("aa.\n..b\n..b\n");
        return 0;
    }else if(N == 6){
        printf("aa....\n..b...\n..b...\n...aa.\n.....b\n.....b\n");
        return 0;
    }

    dp[0] = 0;
    dp[1] = 1001;
    dp[2] = 1001;
    dp[3] = 1001;
    dp[4] = 1;
    dp[5] = 1;
    dp[6] = 1001;
    dp[7] = 1;
    for(int i = 8; i <= N; i ++){
        dp[i] = N;
        for(int j: {4,5,7}){
            //printf("i=%d j=%d\n", i, j);
            dp[i] = min(dp[i], 1+dp[i-j]);
        }
        //printf("dp[%d]=%d\n", i, dp[i]);
    }

    for(int i = 0; i < N; i ++){
        for(int j = 0; j < N; j ++){
            ans[i][j] = '.';
        }
    }

    int n = N;
    while(n){
        for(int j: {4,5,7}){
            if(dp[n] == dp[n-j]+1){
                //printf("n=%d j=%d\n", n, j);
                for(int i = n-j; i < n; i ++){
                    for(int k = n-j; k < n; k ++){
                        ans[i][k] = domino[j][i-(n-j)][k-(n-j)];
                    }
                }
                n -= j;
                break;
            }
        }
    }

    for(int i = 0; i < N; i ++){
        printf("%s\n", ans[i]);
    }
}
