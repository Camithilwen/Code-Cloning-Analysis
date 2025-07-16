#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
int A[3][100001];
LL dp[3][100001] = {};

int main() {
    scanf("%d", &N);
    rep(j, 3) { rep(i, N) scanf("%d", &A[j][i]); A[j][N] = 1000000001; }
    rep(j, 3) sort(A[j], A[j] + N);
    rep(i, N + 1) dp[0][i] = i;
    rep(j, 2) {
        int p = 0;
        rep(i, N) {
            while (A[j][p] < A[j + 1][i]) p++;
            dp[j + 1][i + 1] += dp[j + 1][i] + dp[j][p];
        }
    }
    printf("%lld\n", dp[2][N]);
    return 0;
}