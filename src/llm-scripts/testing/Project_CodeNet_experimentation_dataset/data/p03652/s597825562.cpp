// Template
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <cmath>
#define rep(i, x) for (int i = 0; i < (x); ++i)
#define rng(i, x, y) for (int i = (x); i < (y); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}

// Main Code
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) rep(j, m) {
        cin >> a[i][j];
        --a[i][j];
    }
    
    vector<bool> use(m, true);
    int ans = inf;
    while (true) {
        vector<int> cnt(m, 0);
        rep(i, n) rep(j, m) {
            if (use[a[i][j]]) {
                ++cnt[a[i][j]];
                break;
            }
        }
        int mx = 0;
        rep(i, m) chmax(mx, cnt[i]);
        if (mx == 0) break;
        chmin(ans, mx);
        rep(i, m) {
            if (cnt[i] == mx) use[i] = false;
        }
    }
    
    cout << ans << "\n";
    return 0;
}
