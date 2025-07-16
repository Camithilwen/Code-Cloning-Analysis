#include<cstdio>
using ull = unsigned long long;
const static int MOD = 1000000007;
const static int MAX_H = 100;
const static int MAX_W = 8;
ull dp[MAX_H+1][MAX_W], fibonacci[8] = {1, 1, 2, 3, 5, 8, 13, 21};

int main(){
    unsigned H, W, K;
    scanf("%u %u %u", &H, &W, &K);
    if(W == 1){
        printf("1\n");
        return 0;
    }
    K--;
    dp[0][0] = 1;
    for (size_t i = 1; i <= H; i++){
        dp[i][0] = (dp[i-1][0]*fibonacci[W-1] + dp[i-1][1]*fibonacci[W-2]) %MOD;
        for (size_t j = 1; j < W-1; j++){
            dp[i][j] = (dp[i-1][j-1]*fibonacci[j-1]*fibonacci[W - j - 1] + dp[i-1][j]*fibonacci[j]*fibonacci[W - j - 1] + dp[i-1][j+1]*fibonacci[j]*fibonacci[W - j - 2]) %MOD;
        }
        dp[i][W-1] = (dp[i-1][W-1]*fibonacci[W-1] + dp[i-1][W-2]*fibonacci[W-2]) %MOD;        
    }
    printf("%llu\n", dp[H][K]);
	return 0;
}