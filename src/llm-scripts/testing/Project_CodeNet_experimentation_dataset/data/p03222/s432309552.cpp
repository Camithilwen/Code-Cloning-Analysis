#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1001001001;
const ll mod = 1000000007;

ll dp[105][11];

int main(){
    int h, w, k; cin >> h >> w >> k;
    dp[0][1] = 1;
    for(int i = 1; i <= h; i++){
        for(int l = 1; l <= w; l++){
            ll a = 0, b = 0, c = 0;
            for(int j = 0; j < (1 << w-1); j++){
                bool ok = true;
                for(int m = 0; m < w - 2; m++){
                    if(j & (1 << (m + 1)) && j & (1 << m)) ok = false;
                }
                if(!ok) continue; 
                int mask1 = 1 << (l - 1), mask2 = 1 << (l - 2);
                if(l >= 2 && (mask2 & j)) a++;
                else if(mask1 & j) c++;
                else b++;
            }
            dp[i][l] = (dp[i-1][l-1]*a%mod+dp[i-1][l]*b%mod + dp[i-1][l+1]*c%mod)%mod;
        }
    }
    cout << dp[h][k] << endl;
}