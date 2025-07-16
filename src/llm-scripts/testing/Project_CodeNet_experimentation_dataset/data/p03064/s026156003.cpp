#include<iostream>
using namespace std;
typedef long long ll;

const int MAX_N = 303;
const int MAX_A = 303;
const ll MOD = 998244353;

ll A[MAX_N], dp[MAX_N][MAX_N * MAX_A], sub_dp[MAX_N][MAX_N * MAX_A];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    // main
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = (dp[i][j] + (dp[i - 1][j] * 2) % MOD) % MOD;
            if (j - A[i] >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - A[i]]) % MOD;
        }
    }
    // sub
    sub_dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= sum; j++) {
            sub_dp[i][j] = (sub_dp[i][j] + sub_dp[i - 1][j]) % MOD;
            if (j - A[i] >= 0) sub_dp[i][j] = (sub_dp[i][j] + sub_dp[i - 1][j - A[i]]) % MOD;
        }
    }
    ll not_ans = (MOD - (sum % 2 == 0 ? sub_dp[N][sum / 2] : 0)) % MOD;
    for (int i = (sum + 1) / 2; i <= sum; i++) {
        not_ans = (not_ans + dp[N][i]) % MOD;
    }
    ll ans = 1;
    for (int i = 0; i < N; i++) ans = (ans * 3) % MOD;
    cout << (ans - (3 * not_ans) % MOD + MOD) % MOD << endl;
    return 0;
}