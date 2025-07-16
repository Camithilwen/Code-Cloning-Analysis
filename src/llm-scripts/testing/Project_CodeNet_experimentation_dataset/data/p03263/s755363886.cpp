#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef tuple<int, int, int, int> T;

int H, W;
int a[510][510];
vector<T> ans;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> H >> W;
    rep(i, H) rep(j, W) cin >> a[i][j];
    rep(i, H) {
        if (i%2==0) {
            rep(j, W) {
                if (i==H-1 && j==W-1) continue;
                int ni, nj;
                if (j==W-1) ni = i+1, nj = W-1;
                else ni = i, nj = j+1;
                if (a[i][j]%2==1) {
                    ans.pb(make_tuple(i+1, j+1, ni+1, nj+1));
                    a[ni][nj]++;
                }
            }
        }
        else {
            for (int j=W-1; j>=0; j--) {
                if (i==H-1 && j==0) continue;
                int ni, nj;
                if (j==0) ni = i+1, nj = 0;
                else ni = i, nj = j-1;
                if (a[i][j]%2==1) {
                    ans.pb(make_tuple(i+1, j+1, ni+1, nj+1));
                    a[ni][nj]++;
                }
            }
        }
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << " " << get<3>(ans[i]) << endl;
}