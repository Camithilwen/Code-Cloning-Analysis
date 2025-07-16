#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    int n, t;
    cin >> n >> t;
    vector<P> ti_ta(n);
    rep(i,n) cin >> ti_ta[i].first >> ti_ta[i].second;
    sort(ti_ta.begin(), ti_ta.end());

    vector<vector<int>> dp(n, vector<int>(t+1, 0));
    rep(i,t+1) {
        if (i >= ti_ta[0].first) dp[0][i] = ti_ta[0].second;
    }

    int ans = 0;
    rep(i,n) {
        rep(ti,t+1) {
            if(i == n-1) break;
            // i+1番目の食べ物を食べるときにi番目までの食べ物を食べるのにかかる時間
            int nti = ti - ti_ta[i+1].first;
            // もしi+1番目の食べ物を食べると制限時間内に食べ終わらないとき
            if (nti < 0) dp[i+1][ti] = dp[i][ti];
            // もしi+1番目の食べ物を食べないほうがいいときor食べたほうがいいとき
            else dp[i+1][ti] = max(dp[i][ti], dp[i][nti] + ti_ta[i+1].second);
        }
        int ans_tmp;
        if (i == 0) ans_tmp = ti_ta[0].second;
        else ans_tmp = dp[i-1][t-1] + ti_ta[i].second;
        ans = max(ans, ans_tmp);
    }
    cout << ans << endl;
    return 0;
}