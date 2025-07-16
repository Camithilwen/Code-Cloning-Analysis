#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main() {
    int N; cin >> N;
    vector<tuple<int, int, int>> A(N);
    for (int i = 0; i < N; i++) {
        int h, p; cin >> h >> p;
        A[i] = make_tuple(h + p, h, p);
    }
    sort(begin(A), end(A));
    const Int INF = 1e18;
    vector<Int> dp(N+1, INF), dp2;
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        dp2 = dp;
        int h = get<1>(A[i]), p = get<2>(A[i]);
        for (int j = 0; j < N; j++) {
            if (dp2[j] == INF || dp2[j] > h) {
                break;
            }
            dp[j+1] = min(dp[j+1], dp2[j] + p);
        }
    }
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        if (dp[i] != INF) {
            ans = i;
        }
    }
    cout << ans << '\n';
    return 0;
}
