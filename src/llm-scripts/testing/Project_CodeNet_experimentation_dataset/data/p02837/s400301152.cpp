#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<P> tell[15];

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
            tell[i].emplace_back(x,y);
        }
    }
    int ans = 0;
    rep(is,1<<n) {
        int cnt = __builtin_popcount(is);
        bool ok = true;
        rep(i,n) {
            if (!(is>>i&1)) continue;
            for (auto p : tell[i]) {
                int x = p.first, y = p.second;
                if (!(int(is>>x&1) == y)) ok = false;
            } 
        }
        if (ok) ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}