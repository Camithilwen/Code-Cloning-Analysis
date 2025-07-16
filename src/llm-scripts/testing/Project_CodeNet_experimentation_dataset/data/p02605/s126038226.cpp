#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()

const ll INF = 1e18;
ll N;
ll X[200000], Y[200000];
char U[200000];

ll get_min(char first, char second, ll sign) {
    map<ll, set<ll>> m;
    REP(i, N) {
        if (U[i] != first) continue;
        ll line = Y[i] + sign * X[i];
        if (m.count(line) == 0) {
            set<ll> set {Y[i]};
            m[line] = set;
        } else {
            m[line].insert(Y[i]);
        }
    }

    ll ret = INF;
    REP(i, N) {
        if (U[i] != second) continue;
        ll line = Y[i] + sign * X[i];
        if (m.count(line) == 0) continue;
        auto it = m[line].lower_bound(Y[i]);
        if (it != m[line].begin()) {
            it--;
            ret = min(ret, (Y[i] - *it) * 10);
        }
    }
    return ret;
}

ll get_min_same_line() {
    ll ret = INF;
    map<ll, set<ll>> m;
    REP(i, N) {
        if (U[i] != 'U') continue;
        if (m.count(X[i]) == 0) {
            set<ll> set {Y[i]};
            m[X[i]] = set;
        } else {
            m[X[i]].insert(Y[i]);
        }
    }
    REP(i, N) {
        if (U[i] != 'D' || m.count(X[i]) == 0) continue;
        auto it = m[X[i]].lower_bound(Y[i]);
        if (it != m[X[i]].begin()) {
            it--;
            ret = min(ret, (Y[i] - *it) * 5);
        }
    }

    m.clear();
    REP(i, N) {
        if (U[i] != 'R') continue;
        if (m.count(Y[i]) == 0) {
            set<ll> set {X[i]};
            m[Y[i]] = set;
        } else {
            m[Y[i]].insert(X[i]);
        }
    }
    REP(i, N) {
        if (U[i] != 'L' || m.count(Y[i]) == 0) continue;
        auto it = m[Y[i]].lower_bound(X[i]);
        if (it != m[Y[i]].begin()) {
            it--;
            ret = min(ret, (X[i] - *it) * 5);
        }
    }
    return ret;
}

int main() {
    cin >> N;
    REP(i, N) cin >> X[i] >> Y[i] >> U[i];
    ll ans = INF;
    ans = min(ans, get_min('R', 'D', -1));
    ans = min(ans, get_min('U', 'L', -1));
    ans = min(ans, get_min('L', 'D', 1));
    ans = min(ans, get_min('U', 'R', 1));
    ans = min(ans, get_min_same_line());
    if (ans == INF) cout << "SAFE" << endl;
    else cout << ans << endl;
    return 0;
}