#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
using namespace std;
typedef pair<ll,ll> pll;


vector< pll > v;
ll n;
ll h[5005], p[5005];
ll dp[5005][5005];
const ll inf = 1e16;
int main()
{
        cin >> n;
        v.pb(make_pair(-2LL , -2LL));
        for(ll i=1;i<=n;i++) {
                cin >> h[i] >> p[i];
                v.pb(make_pair(h[i]+p[i], i));
        }
        sort(v.begin(), v.end());
        for(ll i=1;i<=n;i++) dp[0][i] = inf;
        dp[0][0] = 0;
        for(ll i=1;i<=n;i++) {
                ll id = v[i].second;
                for(ll j = 0; j <= n; j++) {
                        dp[i][j] = dp[i-1][j];
                        if(j && dp[i-1][j-1] <= h[id]) dp[i][j] = min(dp[i][j], p[id] + dp[i-1][j-1]);
                }
        }
        for(ll i=n;i>=0;i--){
                if(dp[n][i] != inf) {
                        cout << i << endl; return 0;
                }
        }
        return 0;
}
