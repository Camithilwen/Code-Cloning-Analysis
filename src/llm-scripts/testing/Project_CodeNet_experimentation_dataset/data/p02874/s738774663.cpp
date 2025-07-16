#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef tuple<ll, ll, ll> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define REP(i,n) for (ll i = 0; i < n; ++i)
#define REPR(i,n) for (ll i = n-1; i >= 0; --i)
#define FOR(i,m,n) for (ll i = m; i < n; ++i)
#define FORR(i,m,n) for (ll i = n-1; i >= m; --i)
#define FORE(x,xs) for (const auto& x : xs)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)

const int MAX = 2e5+10;

int N;
vii lr;

ll solve() {
    ll mx = 0, mn = 1e10;
    ll ans = 0;
    FORE (x, lr) {
        CHMAX(mx, x.first);  // 最も右にある左端, X
        CHMIN(mn, x.second); // 最も左にある右端, Y
        CHMAX(ans, x.second - x.first); // 最長の区間
    }
    ans += max(0ll, mn - mx); // 最長以外を反対にした場合

    vii t;
    FORE (x, lr) {
        ll a = max(0ll, x.second - mx); // Xと同じグループにした時の範囲
        ll b = max(0ll, mn - x.first);  // Yと同じグループにした時の範囲
        t.push_back(make_pair(a, -b));
    }
    sort(ALL(t));
    REP (i, N) t[i].second *= -1;
    ll w = t[0].second;
    FOR (i, 1, N) {
        CHMAX(ans, w + t[i].first);
        CHMIN(w, t[i].second);
    }

    return ans;
}

int main() {
    cin >> N;
    REP (i, N) {
        int l, r;
        cin >> l >> r;
        lr.push_back(make_pair(l, r+1));
    }
    cout << solve() << endl;
}