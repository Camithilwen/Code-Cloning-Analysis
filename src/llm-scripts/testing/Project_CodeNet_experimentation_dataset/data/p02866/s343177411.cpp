#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

const int mod = 998244353;

int main() {
    int n, d0;
    cin >> n >> d0;

    if(d0 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> d(100005);
    d.at(0) = 1;
    int max_d = 0;
    for(int i = 1; i < n; ++i) {
        int di;
        cin >> di;
        max_d = max(max_d, di);
        d.at(di)++;
    }

    if(d.at(0) != 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    int i = 1;
    while(i < n) {
        if(d.at(i) == 0) break;
        rep(j, d.at(i)) {
            ans *= d.at(i-1);
            ans %= mod;
        }
        ++i;
    }
    if(i < max_d) cout << 0 << endl;
    else cout << ans << endl;

    return 0;
}