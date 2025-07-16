#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void chmax(ll &a, const ll b) { if (a < b) a = b; return; }
const ll INF = 1ll<<60;

int main() {
    int n; cin >> n;
    vector<ll> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    if (n % 2 == 0) {
        ll count = 0;
        for (int i = 0; i < n; i += 2) count += a[i];
        ll ans = count;
        for (int i = n-2; i >= 0; i -= 2) {
            count += a[i+1];
            count -= a[i];
            chmax(ans,count);
        }
        cout << ans << endl;
        return 0;
    }
    else {
        vector<vector<ll>> dp(n+2,vector<ll>(3,-INF));
        dp[0][0] = 0ll;
        for (int i = 1; i <= n+1; i++) {
            for (int j = 0; j < 3; j++) {
                if (i-2 >= 0) chmax(dp[i][j], dp[i-2][j] + a[i-2]);
            }
            for (int j = 1; j < 3; j++) {
                if (i-1 >= 0) chmax(dp[i][j], dp[i-1][j-1]);
            }
        }
        cout << dp[n+1][2] << endl;
        return 0;
    }
}