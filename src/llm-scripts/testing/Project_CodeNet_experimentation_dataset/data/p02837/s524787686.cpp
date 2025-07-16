#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

vector<P> test[15];

int main() {
    int n;
    cin >> n;
    rep(i,n) {
        int a;
        cin >> a;
        rep(j,a) {
            int x, y;
            cin >> x >> y;
            x--;
            test[i].emplace_back(x,y);
        }
    }

    int ans = 0;
    rep(is,1<<n) {
        int cnt = __builtin_popcount(is);
        bool ok = true;
        rep(i,n) {
            if (is>>i&1) {
                for (auto p : test[i]) {
                    int x = p.first, y = p.second;
                    int t = is>>x&1;
                    if (t != y) ok = false;
                }
            }
        }
        if (ok) ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}