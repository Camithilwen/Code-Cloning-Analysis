#include <bits/stdc++.h>
using namespace std;
#define int         long long
#define endl        "\n"
#define pii         pair<int, int>
#define dint        long double

// tourist

bool cmp(pii a, pii b) {
    return (a.first + a.second < b.first + b.second);
}

const int inf = 1e18;

void solve() {
    int n; cin >> n;
    pii a[n+1];
    for(int i=1; i<=n; i++) {
        cin >> a[i].first >> a[i].second;
    }  
     // First -> Strenght, Second -> Weight
    sort(a+1, a+n+1, cmp);
    int dp[n+1][n+1];
    for(int i=0; i<=n; i++) for(int j=0; j<=n; j++) dp[i][j] = inf;
    dp[0][0] = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            int wt = dp[i][j];
            if(wt == inf) continue;
            dp[i+1][j] = min(dp[i+1][j], wt);
            if(wt <= a[i+1].first) {
                dp[i+1][j+1] = min(dp[i+1][j+1], wt + a[i+1].second);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=n; i++) {
        if(dp[n][i] != inf) {
            ans = i;
        }
    }
    cout << ans << endl;
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(12);

    int T = 1;
    //cin >> T;
    for(int i=1; i<=T; i++) {
        solve();
    }
    return 0;

}

