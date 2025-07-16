#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LL MOD = 1e9 + 7;
LL cal(int S, auto &arr, auto &sum) {
    if (~sum[S]) return sum[S];
    sum[S] = 0; int n = arr.size();
    for (int i = 0 ; i < n ; i++)
        for (int j = i + 1 ; j < n ; j++)
            if (((S >> i) & 1) & ((S >> j) & 1))
                sum[S] += arr[i][j];
    return sum[S];
}
LL solve(int S, auto &dp, auto &arr, auto &sum) {
    if (~dp[S]) return dp[S];
    dp[S] = 0;
    for (int s = S ; s ; s = (s - 1) & S)
        dp[S] = max(dp[S], solve(S ^ s, dp, arr, sum) + cal(s, arr, sum));
    return dp[S];
}
void marmot0814() {
    int n; cin >> n;
    vector<vector<LL>> arr(n, vector<LL>(n));
    for (auto &vv : arr)
        for (auto &v : vv)
            cin >> v;
    vector<LL> dp(1 << n, -1); dp[0] = 0;
    vector<LL> sum(1 << n, -1);
    cout << solve((1 << n) - 1, dp, arr, sum) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}