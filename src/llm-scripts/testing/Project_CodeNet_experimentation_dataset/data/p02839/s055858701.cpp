#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    int H,W; cin >> H >> W;
    vector<vector<int>> A(H,vector<int>(W));
    rep(i,H)rep(j,W) cin >> A[i][j];
    vector<vector<int>> B(H,vector<int>(W));
    rep(i,H)rep(j,W) cin >> B[i][j];

    vector<vector<int>> before(W,vector<int>(12800,0));
    vector<vector<int>> now(W,vector<int>(12800,0));
    before[0][6400] = 1;
    rep(i,H) {
        rep(j,W) {
            int a = A[i][j];
            int b = B[i][j];
            rep(k,12800) {
                if (before[j][k] == 0) continue;
                if (0 <= k + a - b && k + a - b < 12800) {
                    if (j + 1 < W) before[j + 1][k + a - b] = 1;
                    if (i + 1 < H) now[j][k + a - b] = 1;
                }
                if (0 <= k + b - a && k + b - a < 12800) {
                    if (j + 1 < W) before[j + 1][k + b - a] = 1;
                    if (i + 1 < H) now[j][k + b - a] = 1;
                }
            }
        }
        if (i == H - 1) break;
        swap(before,now);
        now = vector<vector<int>>(W,vector<int>(12800,0));
    }
    //rep(i,W)for (int j = 6200;j< 6500;j ++) printf("before[%d][%d]   %d   ",i,j,before[i][j]);

    int ans = INF;
    int a = A[H - 1][W - 1],b = B[H - 1][W - 1];
    rep(i,12800) {
        if ((0 <= i + a - b && i + a - b < 12800 && before[W - 1][i + a - b])
            || (0 <= i + b - a && i + b - a < 12800 && before[W - 1][i + b - a])) {
                ans = min(ans,abs(i - 6400));
            }
    }
    cout << ans << endl;
    return 0;
}