#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using ll = long long;
using namespace std;
constexpr ll inf = 1e15;

#define MAX_N 1000

constexpr int MAX = 10000;
constexpr int MOD = 1e9+7;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// dp[i][j] := 最大のグループ人数がj人であるとき、i人をグループ分けする場合の数
ll dp[MAX_N+1][MAX_N+1] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, A, B, C, D;
    cin>>N>>A>>B>>C>>D;

    for (int i = 0; i <= B; i++) dp[0][i] = 1;

    COMinit();
    
    for (int n = 1; n <= N; n++) {
        for (int i = A; i <= B; i++) {
            ll comb = 1;
            dp[n][i] = dp[n][i-1];
            for (int j = 1; j < C; j++) comb = (((comb * COM(n - i * (j - 1), i)) % MOD) * inv[j]) % MOD;
            for (int j = C; j <= min(D, (n/i)); j++) {
                 ll F = i * j;
                 comb = (((comb * COM(n - i * (j - 1), i)) % MOD) * inv[j]) % MOD;
                 dp[n][i] = (dp[n][i] + (dp[n - F][i - 1] * comb % MOD)) % MOD;
            }
        }
    }

    cout<<dp[N][B]<<endl;

    return 0;
}