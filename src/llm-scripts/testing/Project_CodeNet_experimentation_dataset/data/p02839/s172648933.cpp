#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int H, W;
bitset<160 * 160 + 1> dp[81][81];
int cost[81][81];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> H >> W;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> cost[i][j];
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            int tmp;
            cin >> tmp;
            cost[i][j] -= tmp;
        }
    }

    int s = H + W - 1;
    dp[0][0][80 + cost[0][0]] = true;
    dp[0][0][80 - cost[0][0]] = true;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            dp[i + 1][j] |= dp[i][j] << (80 + cost[i + 1][j]);
            dp[i + 1][j] |= dp[i][j] << (80 - cost[i + 1][j]);
            dp[i][j + 1] |= dp[i][j] << (80 + cost[i][j + 1]);
            dp[i][j + 1] |= dp[i][j] << (80 - cost[i][j + 1]);
        }
    }

    int ans = inf;
    for(int i = 0; i <= s * 160; i++){
        if(!dp[H - 1][W - 1][i]) continue;
        chmin(ans, abs(i - s * 80));
    }
    cout << ans << endl;
    return 0;
}