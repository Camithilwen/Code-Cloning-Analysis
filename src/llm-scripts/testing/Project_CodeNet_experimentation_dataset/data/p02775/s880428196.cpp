#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    string N_str;
    cin >> N_str;
    int n = N_str.length();

    vector<int> N(n, 0);
    rep(i,n) N[i] = N_str[n - 1 - i] - '0';

    vector<vector<int>> dp(n + 1, vector<int>(2, INF));
    dp[0][0] = 0;

    rep(i,n) rep(j,2) {
        N[i] += j;
        rep(A,10) {
            int p = i + 1, q = 0;
            int B = A - N[i];
            if (B < 0) {
                q = 1;
                B += 10;
            }
            dp[p][q] = min(dp[p][q], dp[i][j] + A + B);
        }
        N[i] -= j;
    }

    cout << min(dp[n][0], dp[n][1] + 1) << endl;
    
    return 0;
}