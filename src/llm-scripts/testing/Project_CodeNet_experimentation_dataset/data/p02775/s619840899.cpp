#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }

const int INF = 1e9;

int main() {
    string S; cin >> S;
    int N = S.size();
    vector<vector<int>> dp(N + 1, vector<int>(2, INF));
    dp[0][0] = 0;
    for(int i = 0; i < N; ++i) {
        int d = S[i] - '0';
        chmin(dp[i + 1][0], min(dp[i][0], dp[i][1]) + d);
        chmin(dp[i + 1][1], min(dp[i][0] + 1, dp[i][1] - 1) + 10 - d);
    }
    cout << min(dp[N][0], dp[N][1]) << '\n';
    return 0;
}
