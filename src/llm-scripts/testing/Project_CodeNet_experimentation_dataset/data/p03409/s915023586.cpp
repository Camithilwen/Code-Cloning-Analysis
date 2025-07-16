#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    // 解説AC
    int n;
    cin >> n;
    pint red[n], blue[n];
    rep (i, 0, n) cin >> red[i].first >> red[i].second;
    rep (i, 0, n) cin >> blue[i].first >> blue[i].second;
    sort (red, red + n);
    sort (blue, blue + n);
    bool chk[n] = {};
    int ans = 0;
    // まず、redの点を固定する
    per (i, 0, n) {
        int res = -1;
        int now = inf;
        per (j, 0, n) {
            if (chk[j]) continue;
            if (red[i].first < blue[j].first &&
                red[i].second < blue[j].second) {
                // 条件に当てはまる中でblueのyが最も小さいのを選ぶ
                if (now > blue[j].second) {
                    res = j;
                    now = blue[j].second;
                }
            }
        }
        if (res != -1) {
            chk[res] = 1;
            ans++;
        }
    }
    cout << ans << "\n";
}