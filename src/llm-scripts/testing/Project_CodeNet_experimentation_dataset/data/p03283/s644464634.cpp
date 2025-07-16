#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

const int MAX_N = 500;

int N, M, Q;
int L, R;
int p, q;

int cnt[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main() {
    cin >> N >> M >> Q;
    REP(i, N) {
        REP(j, N) {
            cnt[i][j] = 0;
            dp[i][j] = 0;
        }
    }
    REP(i, M) {
        cin >> L >> R; L--; R--;
        cnt[L][R]++;
    }

    REP(i, N) dp[i][i] = cnt[i][i];

    REP2(k, 1, N) {
        REP(i, N-k) {
            int j = i + k;
            dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + cnt[i][j];
        }
    }
    
    REP(i, Q) {
        cin >> p >> q; p--; q--;
        PRINT(dp[p][q]);
    }

    return 0;
}