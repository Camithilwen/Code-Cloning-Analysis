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
#define FORI(i,v) for (auto i = v.begin(); i != v.end(); i++)
#define ALL(v) v.begin(), v.end()
#define CHMIN(x,y) x = min(x, y)
#define CHMAX(x,y) x = max(x, y)
#define YES(b) cout << ((b) ? "YES" : "NO") << endl
#define Yes(b) cout << ((b) ? "Yes" : "No") << endl

const int MAX = 2e5+10;
const int INF = 1e9+10;

int N;
vii U, D, R, L;

vii holRev(vii v) {
    vii ret;
    FORE (xy, v) {
        int x, y; tie(x, y) = xy;
        ret.push_back(ii(MAX-x, y));
    }
    return ret;
}

vii verRev(vii v) {
    vii ret;
    FORE (xy, v) {
        int x, y; tie(x, y) = xy;
        ret.push_back(ii(x, MAX-y));
    }
    return ret;
}

int sub1(vii r, vii l, bool hol) {
    int ret = INF;
    vector<set<int>> u(MAX);
    FORE (xy, l) {
        int x, y; tie(x, y) = xy; if (!hol) swap(x, y);
        u[y].insert(x);
    }
    FORE (xy, r) {
        int x, y; tie(x, y) = xy; if (!hol) swap(x, y);
        auto it = u[y].upper_bound(x);
        if (it != u[y].end()) {
            CHMIN(ret, (*it - x) * 5);
        }
    }

    return ret;
}

int sub2(vii uu, vii r) {
    int ret = INF;
    vector<set<int>> u(2*MAX+10);
    FORE (xy, uu) {
        int x, y; tie(x, y) = xy;
        u[x+y].insert(x);
    }
    FORE (xy, r) {
        int x, y; tie(x, y) = xy;
        auto it = u[x+y].upper_bound(x);
        if (it != u[x+y].end()) {
            CHMIN(ret, (*it - x) * 10);
        }
    }

    return ret;
}

int solve() {
    int ret = INF;

    // 正面衝突
    CHMIN(ret, sub1(R, L, true));
    CHMIN(ret, sub1(U, D, false));

    // 直行衝突
    CHMIN(ret, sub2(U, R));
    CHMIN(ret, sub2(holRev(U), holRev(L)));
    CHMIN(ret, sub2(verRev(D), verRev(R)));
    CHMIN(ret, sub2(holRev(verRev(D)), holRev(verRev(L))));

    return ret;
}

int main() {
    cout << fixed << setprecision(15);
    cin >> N;
    REP (i, N) {
        int x, y, c; char u; cin >> x >> y >> u;
        if (u == 'U') U.push_back(ii(x, y));
        else if (u == 'R') R.push_back(ii(x, y));
        else if (u == 'D') D.push_back(ii(x, y));
        else L.push_back(ii(x, y));

    }
    int ans = solve();
    if (ans == INF) cout << "SAFE" << endl;
    else cout << ans << endl;
}