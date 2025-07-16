#include <bits/stdc++.h>

using namespace std;
using ll=long long;
#define rep(i,n)  for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

#define MOD 1000000007

int main(){
    ll h, w, k;
    cin >> h >> w >> k;

    ll dp[110][10] = {};
    dp[0][0] = 1;

    rep(i, h)rep(j, w)rep(k,(1<<(w-1))){  
        bool isok = true;
        rep(l, w-2)if(k & (1<<l) && k & (1<<(l+1))){
            isok = false;
            break;
        }
        if(isok){
            if(j > 0 && (1<<(j-1) & k)){
                dp[i+1][j-1] += dp[i][j];
                dp[i+1][j-1] %= MOD;
            }
            else if(j < w-1 && (1<<j) & k){
                dp[i+1][j+1] += dp[i][j];
                dp[i+1][j+1] %= MOD;
            }
            else {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }
        }
    }

    cout << dp[h][k-1] << endl;
    
}