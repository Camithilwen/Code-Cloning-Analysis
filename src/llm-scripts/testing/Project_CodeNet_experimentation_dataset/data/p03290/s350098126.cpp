#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 1e5 + 2;
int n, k, p[11], c[11];
ll dp[11][A];
ll solve(int ind, int rem) {
    if (rem <= 0) return 0;
    if (ind == n) return 1e9;
    if (~dp[ind][rem])
        return dp[ind][rem];
    ll val = solve(ind + 1, rem - (p[ind] * (ind + 1)) - c[ind]) + p[ind];
    for (int i = 0; i < p[ind]; i++)
        val = min(val, solve(ind + 1, rem - (i * (ind + 1))) + i);
    return dp[ind][rem] = val;
}
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    k /= 100;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }
    memset(dp, -1, sizeof dp);
    cout << solve(0, k);
    return 0;
}