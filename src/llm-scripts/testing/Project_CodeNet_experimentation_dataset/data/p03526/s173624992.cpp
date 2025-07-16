/*
DISCLAIMER: I don't expect this to AC first submit, but it'd be pretty great if it did...
 -> I'm rusty af
*/
 
 
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //gp_hash_table
 
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define sz(a) (int) a.size()
#define bitcount(a) __builtin_popcount(a)
#define bitcountll(a) __builtin_popcountll(a)
 
using namespace std;
// using namespace __gnu_pbds;
 
 
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
 
void solve() {
    const ll oo = 1e18;
    int n; cin >> n;
    vector<pii> a(n);
    for(auto& p : a) cin >> p.first >> p.second;
    sort(all(a), [](const pii& x, const pii& y) {
        int l = x.first - y.second;
        int r = y.first - x.second;
        return l < r;
    });
    a.insert(a.begin(), {-1, -1});
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, oo));
    int ans = 0;
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = 0;
        for(int x = 1; x <= i; ++x) {
            dp[i][x] = dp[i - 1][x];
            if(dp[i - 1][x - 1] <= a[i].first) {
                dp[i][x] = min(dp[i][x], dp[i - 1][x - 1] + a[i].second);
            }
            if(dp[i][x] < oo) {
                ans = max(ans, x);
            }
        }
    }
    cout << ans << endl;
}
 
int main() {
    // freopen("input.in", "r", stdin);
    // freopen("input.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
    cout << fixed;
    // int t; cin >> t; while(t--)
    solve();
    cout.flush();
    return 0;
}
