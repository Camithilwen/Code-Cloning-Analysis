#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

const ll MOD = 1e9+7;
ll dp[101][8];

int main(){
    ll h, w, k; cin >> h >> w >> k;
    
    if(w == 1){ cout << 1 << endl; return 0; }
    
    dp[0][0] = 1;
    rep(i,h){
        rep(j,1<<(w-1)){
            vector<bool> count(w-1,false);
            rep(k,w-1) if(j & 1<<k) count[k] = true;
            bool check = false;
            rep(k,w-2) if(count[k] && count[k+1]) check = true;
            if(check) continue;

            rep(k,w-1){
                if(count[k]){
                    dp[i+1][k+1] += dp[i][k];
                    dp[i+1][k+1] %= MOD;
                    dp[i+1][k] += dp[i][k+1];
                    dp[i+1][k] %= MOD;
                }
                else if(k == 0){
                    dp[i+1][0] += dp[i][0];
                    dp[i+1][0] %= MOD;
                }
                else if(!count[k-1]){
                    dp[i+1][k] += dp[i][k];
                    dp[i+1][k] %= MOD;
                }
                if(!count[k] && k == w-2){
                    dp[i+1][w-1] += dp[i][w-1];
                    dp[i+1][w-1] %= MOD;
                }
            }
        }
    }

    cout << dp[h][k-1] << endl;
}

