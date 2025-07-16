#include <bits/stdc++.h>

using namespace std;
const int N = 302;
double dp[N][N][N];
int n;
int cnt[4];


int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }

    for(int k = 0;k <= cnt[3];k++){
        for(int j = 0;j <= cnt[2] + cnt[3] - k;j++){
            for(int i = 0;i <= n - j;i++){
                if(i == 0 && j == 0 && k == 0)
                    continue;
                dp[i][j][k] = 1;
                if(i)
                    dp[i][j][k] += 1.0 * i / n * dp[i - 1][j][k];
                if(j)
                    dp[i][j][k] += 1.0 * j / n * dp[i + 1][j - 1][k];
                if(k)
                    dp[i][j][k] += 1.0 * k / n * dp[i][j + 1][k - 1];
                dp[i][j][k] /= 1 - 1.0 * (n - i - j - k) / n;            
            }
        }
    }
    printf("%.10f", dp[cnt[1]][cnt[2]][cnt[3]]);
}