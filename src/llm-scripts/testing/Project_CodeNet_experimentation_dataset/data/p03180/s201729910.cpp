#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define loop(i, r, n) for (int i = (r); i < (n); i++)
using ll = long long;
using namespace std;

void chmax(ll &a, ll b){ if(a < b) a = b; return; }
ll n, a[16][16], dp[1<<16];

int main(){
    cin >> n;
    rep(i,n) rep(j,n) cin >> a[i][j];
    loop(i,1,1<<n){
        rep(j,n) rep(k,j) if(i>>j & i>>k & 1) dp[i] += a[j][k];
        for(int j = i; j > 0; j = (j-1)&i) chmax(dp[i], dp[j]+dp[i^j]);
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}