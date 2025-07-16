#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

constexpr ll mod = 1000000000 + 7;

ll dp[200][10];

void init() {
    rep(i, 0, 200) rep(j, 0, 10) dp[i][j] = 0;
}

int main(){

    init();

    // input
    ll h, w, k;
    cin >> h >> w >> k;

    // dp
    dp[0][0] = 1;
    rep(i, 0, h) {
        rep(j, 0, w) {
            for(int bit = 0; bit < (1<<(w-1)); bit++) {
                bool f = true;
                rep(k, 0, w-2) {
                    if((bit & (1<<k)) && (bit & (1<<(k+1)))) f = false;
                }
                if(!f) continue;
                if(j >= 1 && (bit & (1 << (j-1) ) ) ) {
                    dp[i+1][j-1] += dp[i][j];
                    dp[i+1][j-1] %= mod;
                }else if(j <= w-2 && (bit & (1<<j) ) ) {
                    dp[i+1][j+1] += dp[i][j];
                    dp[i+1][j+1] %= mod;
                }else{
                    dp[i+1][j] += dp[i][j];
                    dp[i+1][j] %= mod;
                }
            }
        }
    }
    
    cout << dp[h][k-1] << endl;
    return 0;
}