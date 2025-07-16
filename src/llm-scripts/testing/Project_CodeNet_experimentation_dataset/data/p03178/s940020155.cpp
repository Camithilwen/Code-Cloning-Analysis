#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const LL MOD = 1e9 + 7;
LL dp[10005][105][2], D;
vector<int> arr;
LL solve(int i, int d, int op) {
    if (i == -1) return d == 0;
    if (~dp[i][d][op]) return dp[i][d][op];
    dp[i][d][op] = 0;
    int up = op ? arr[i] : 9;
    for (int k = 0 ; k <= up ; k++)
        (dp[i][d][op] += solve(i - 1, (d + k) % D, op && (k == arr[i]))) %= MOD;
    return dp[i][d][op];
}
void marmot0814() {
    string s; cin >> s >> D;
    for (auto &c : s)
        arr.push_back(c - '0');
    reverse(arr.begin(), arr.end());
    memset(dp, -1, sizeof(dp));
    cout << (solve(arr.size() - 1, 0, 1) + MOD - 1) % MOD << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1, kase = 0; // cin >> t;
    while (t--) {
        // cout << "Case #" << ++kase << ":";
        marmot0814();
    }
}