#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
const int ofs = 12800;

int H, W;
int A[82][82], B[82][82];
bool dp[82][82][25610];
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> H >> W;
    rep(i, H) rep(j, W) cin >> A[i][j];
    rep(i, H) rep(j, W) cin >> B[i][j];
    dp[0][0][A[0][0]-B[0][0]+ofs] = true;
    dp[0][0][B[0][0]-A[0][0]+ofs] = true;
    
    rep(i, H) rep(j, W) {
        if (i>0) rep(k, 25610) {
            if (!dp[i-1][j][k]) continue;
            int nk = k+A[i][j]-B[i][j];
            if (0<=nk && nk<25610) dp[i][j][nk] = true;
            nk = k+B[i][j]-A[i][j];
            if (0<=nk && nk<25610) dp[i][j][nk] = true;
        }
        if (j>0) rep(k, 25610) {
            if (!dp[i][j-1][k]) continue;
            int nk = k+A[i][j]-B[i][j];
            if (0<=nk && nk<25610) dp[i][j][nk] = true;
            nk = k+B[i][j]-A[i][j];
            if (0<=nk && nk<25610) dp[i][j][nk] = true;
        }
    }
    
    int ans = 1000000;
    rep(i, 25610) if (dp[H-1][W-1][i]) ans = min(ans, abs(i-ofs));
    cout << ans << endl;
}