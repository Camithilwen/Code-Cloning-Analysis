#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LL MOD = 1e9 + 7;
const int MAXV = 1e5 + 5;
double solve(int a, int b, int c, auto &dp, int n) {
    if (dp[a][b][c] != -1) return dp[a][b][c];
    double sum = 0;
    if (a - 1 >= 0)
        sum += solve(a - 1, b, c, dp, n) / n * a;
    if (b - 1 >= 0)
        sum += solve(a + 1, b - 1, c, dp, n) / n * b;
    if (c - 1 >= 0)
        sum += solve(a, b + 1, c - 1, dp, n) / n * c;
    sum++;
    sum *= n, sum /= a + b + c;
    return dp[a][b][c] = sum;
}
void marmot0814() {
    int n; cin >> n;
    vector<LL> cnt(3, 0);
    for (int i = 0 ; i < n ; i++) {
        int v; cin >> v; v--;
        cnt[v]++;
    }
    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, -1)));
    dp[0][0][0] = 0;
    cout << fixed << setprecision(20) << solve(cnt[0], cnt[1], cnt[2], dp, n) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}