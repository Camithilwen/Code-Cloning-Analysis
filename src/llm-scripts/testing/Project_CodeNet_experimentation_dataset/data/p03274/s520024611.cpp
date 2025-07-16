#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    int n,k;
    cin >> n >> k;
    ve<int> x(n),y(n);
    rep(i,n) cin >> x[i];
    rep(i,n) y[i] = -x[n-1-i];
    int ans = 2e9;
    rep(i,n-k+1){
        int memo = abs(x[i]) + (x[i+k-1]-x[i]);
        ans = min(ans,memo);
        memo = abs(y[i]) + y[i+k-1]-y[i];
        ans = min(ans,memo);
    }
    cout << ans << endl;
    return 0;
}
