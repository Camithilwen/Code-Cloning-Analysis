#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    ll h, w;
    cin >> h >> w;
    ll a[h][w];
    rep(i, h) {
        rep(j, w) { cin >> a[i][j]; }
    }
    vector<pair<pair<ll, ll>, pair<ll, ll>>> ans;

    rep(i, h) {
        rep(j, w - 1) {
            if (a[i][j] % 2 == 0) {
                continue;
            }
            a[i][j + 1]++;
            pair<ll, ll> before, after;
            before = make_pair(i, j);
            after = make_pair(i, j + 1);
            ans.push_back(make_pair(before, after));
        }
    }

    rep(i, h - 1) {
        if (a[i][w - 1] % 2 == 0) {
            continue;
        }
        a[i + 1][w - 1]++;
        pair<ll, ll> before, after;
        before = make_pair(i, w - 1);
        after = make_pair(i + 1, w - 1);
        ans.push_back(make_pair(before, after));
    }

    cout << ans.size() << endl;
    for (auto p : ans) {
        cout << p.first.first + 1 << " " << p.first.second + 1 << " "
             << p.second.first + 1 << " " << p.second.second + 1 << endl;
    }

    return 0;
}

