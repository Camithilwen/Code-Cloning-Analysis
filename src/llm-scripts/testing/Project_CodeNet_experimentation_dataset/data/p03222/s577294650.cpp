#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

bool check(int w, int bit){
    bool ok = true;
    vector<int> a(w);
    rep(i, w){
        if(bit & (1<<i))a[i] = 1;
        else a[i] = 0;
    }
    REP(i, w-1)if(a[i] == a[i-1] && a[i] == 1)ok = false;
    return ok;
}

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<ll>> dp(h+1, vector<ll>(w, 0));
    dp[0][0] = 1;
    rep(i, h){
        for(int bit = 0; bit < (1<<(w-1)); bit++){
            if(!check(w-1, bit))continue;
            vector<int> to(w);
            rep(j, w)to[j] = j;
            rep(j, w-1){
                if(bit & (1<<j)){
                    to[j] = j+1;
                    to[j+1] = j;
                }
            }
            rep(j, w){
                dp[i+1][to[j]] += dp[i][j];
                dp[i+1][to[j]] %= mod;
            }
        }
    }
    cout << dp[h][k-1] << endl;
}