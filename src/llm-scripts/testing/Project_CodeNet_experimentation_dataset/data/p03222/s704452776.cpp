#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int dp[105][10];
int mod = 1000000007;

int main() {
    int H, W, K; cin >> H >> W >> K;
    dp[0][0] = 1;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < 1<<(W-1); j++){
            bool ok = true;
            for (int k = 0; k < (W-2); k++){
                if(j>>k&1 == 1 && j>>(k+1)&1 == 1){
                    ok = false;
                }
            }
            if(!ok)continue;
            for (int k = 0; k < W; k++){
                int t = k;
                if(j>>(k-1)&1 == 1)t = k-1;
                if(j>>(k)&1 == 1)t = k+1;
                dp[i+1][t] += dp[i][k];
                dp[i+1][t] %= mod;
            }

        }
    }

    cout << dp[H][K-1] << endl;

    return 0;
}