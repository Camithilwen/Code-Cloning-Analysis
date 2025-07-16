/*
Loading:{
        https://codeforces.com/problemset/problem/1234/F
}
*/
#include <bits/stdc++.h>

using namespace std;

#define ll int // optimize with int
#define endl '\n'
const int N = 1e6 + 5;
ll a[305];
ll dp[305][305][305]; // id, used to donate, used to receive;
ll mod = 998244353; // fucking mod 1e9 + 7
ll n, k, cnt = 0;
ll add(ll x, ll y){ // optimize with add func
        ll res = x + y;
        if (res >= mod) res -= mod;
        return res;
}
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (fopen("GUARDS.INP", "r")){
                freopen("GUARDS.INP", "r", stdin);
                freopen("GUARDS.OUT", "w", stdout);
        }
        string s;
        cin >> s;
        n = s.length();
        cin >> k;
        ll cur = 0;
        ll cnt1 = 0;
        for (int i = s.length() - 1; i >= 0; i--){
                if (s[i] == '1') {
                        cur++;
                        cnt1++;
                }
                else {
                        cnt++;
                        a[cnt] = cur;
                        cur = 0;
                }
        }
        cnt++;
        a[cnt] = cur;
        //memset(dp, -1, sizeof(dp));
        k = min(k, cnt1);
        for (int i = a[1]; i >= max(0, a[1] - k); i--){
                dp[1][a[1] - i][0] = 1;
        }
        ll sum = a[1];
        for (int i = 1; i < cnt; i++){
                for (int j = 0; j <= sum; j++){
                        for (int t = 0; t <= j; t++){
                                dp[i + 1][j][t] = add(dp[i + 1][j][t], dp[i][j][t]);
                                for (int x = a[i + 1] - 1; x >= max(0, (a[i + 1] - (k - j))); x--){
                                        dp[i + 1][j + a[i + 1] - x][t] = add(dp[i + 1][j + a[i + 1] - x][t], dp[i][j][t]);
                                }
                                for (int x = a[i + 1] + 1; x <= a[i + 1] + (j - t); x++){
                                        dp[i + 1][j][t + x - a[i + 1]] = add(dp[i + 1][j][t + x - a[i + 1]], dp[i][j][t]);
                                }
                        }
                }
                sum += a[i + 1];
        }
        ll ans = 0;
        for (int i = 0; i <= k; i++) {
                ans = add(ans, dp[cnt][i][i]);
                //cout << dp[cnt][i][i] << " ";
        }
        cout << ans;
}
