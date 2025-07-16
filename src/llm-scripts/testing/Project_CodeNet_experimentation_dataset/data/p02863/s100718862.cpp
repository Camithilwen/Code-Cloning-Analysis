#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    const int INF = 1000000000;
    int N, T;
    cin >> N >> T;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    vector<vector<int>> dp0(N + 1, vector<int>(T + 1, -INF)), dp1(N + 1, vector<int>(T + 1, -INF));
    dp0[0][0] = 0;
    dp1[N][0] = 0;
    rep(i, N) rep(j, T + 1) {
        dp0[i + 1][j] = max(dp0[i + 1][j], dp0[i][j]);
        if (j + A[i] <= T) dp0[i + 1][j + A[i]] = max(dp0[i + 1][j + A[i]], dp0[i][j] + B[i]);
    }
    for (int i = N; i > 0; --i) rep(j, T + 1) {
        dp1[i - 1][j] = max(dp1[i - 1][j], dp1[i][j]);
        if (j + A[i - 1] <= T) dp1[i - 1][j + A[i - 1]] = max(dp1[i - 1][j + A[i - 1]], dp1[i][j] + B[i - 1]);
    }
    rep(i, N + 1) rep(j, T) {
        dp0[i][j + 1] = max(dp0[i][j], dp0[i][j + 1]);
        dp1[i][j + 1] = max(dp1[i][j], dp1[i][j + 1]);
    }
    int ans = 0;
    rep(i, N) {
        int res = 0;
        rep(j, T) res = max(res, dp0[i][j] + dp1[i + 1][T - 1 - j]);
        ans = max(ans, res + B[i]);
    }
    cout << ans << "\n";
    return 0;
}
