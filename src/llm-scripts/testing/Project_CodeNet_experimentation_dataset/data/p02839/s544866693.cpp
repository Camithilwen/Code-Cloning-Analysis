#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<int> > A(H, vector<int> (W)), B(H, vector<int> (W));
    rep(i,H){
        rep(j,W){
            cin >> A[i][j];
        }
    }
    rep(i,H){
        rep(j,W){
            cin >> B[i][j];
        }
    }
    
    vector<vector<vector<int> > > dp(H, vector<vector<int> >(W, vector<int> (6480)));
    rep(i,H){
        rep(j,W){
            rep(k,6480){
                dp[i][j][k] = 0;
            }
        }
    }
    vector<vector<int> > C(H, vector<int> (W));
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            C[i][j] = abs(A[i][j] - B[i][j]);
        }
    }
    dp[0][0][C[0][0]] = 1;
    for (int i = 0; i < H - 1; i++){
        for (int j = 0; j < W - 1; j++){
            for (int k = 0; k < 6400; k++){
                if (dp[i][j][k] > 0){
                    dp[i][j + 1][abs(k - C[i][j + 1])]++;
                    dp[i][j + 1][abs(k + C[i][j + 1])]++;
                }
            }
        }
        for (int j = 0; j < W; j++){
            for (int k = 0; k < 6400; k++){
                if (dp[i][j][k] > 0){
                    dp[i + 1][j][abs(k - C[i + 1][j])]++;
                    dp[i + 1][j][abs(k + C[i + 1][j])]++;
                }
            }
        }
    }
    for (int j = 0; j < W - 1; j++){
        for (int k = 0; k < 6400; k++){
            if (dp[H - 1][j][k] > 0){
                dp[H - 1][j + 1][abs(k - C[H - 1][j + 1])]++;
                dp[H - 1][j + 1][abs(k + C[H - 1][j + 1])]++;
            }
        }
    }
    int ans = 6479;
    for (int k = 6479; k >= 0; k--){
        if (dp[H - 1][W - 1][k] > 0) ans = k;
    }
    cout << ans << endl;
}
