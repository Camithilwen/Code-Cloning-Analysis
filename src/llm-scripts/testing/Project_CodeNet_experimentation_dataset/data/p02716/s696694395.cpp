#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using WGraph = vector<vector<pair<int, ll>>>;

template<class T>inline bool chmax(T &a, const T &b) { if (b > a) { a = b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

constexpr int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;
constexpr long long LINF = 1e18;
constexpr double EPS = 1e-10;
constexpr double PI = M_PI;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a.at(i);
    }

    ll sumO = 0, sumE = 0;
    for (int i=0; i<n; ++i) {
        if (i % 2 == 0) sumO += a.at(i);
        else sumE += a.at(i);
    }
    if (n % 2 == 0) {
        ll res = sumE;
        ll curO = 0, curE = 0;
        for (int i=0; i<n; ++i) {
            if (i % 2 == 0) {
                curO += a.at(i);
            } else {
                curE += a.at(i);
                chmax(res, sumE + curO - curE);
            }
        }
        cout << res << '\n';
    } else {
        ll res = sumE;
        ll curO = 0, curE = 0;
        vector<ll> diff(n);
        for (int i=0; i<n; ++i) {
            if (i % 2 == 0) {
                curO += a.at(i);
            } else {
                curE += a.at(i);
                chmax(diff.at(i), curO - curE);
                if (i > 1) chmax(diff.at(i), diff.at(i-2));
            }
        }
        chmax(res, sumE + diff.at(n-1));
        curO = curE = 0;
        ll maxi = 0;
        for (int i=n-1; i>=0; --i) {
            if (i % 2 == 0) {
                curO += a.at(i);
            } else {
                curE += a.at(i);
                chmax(maxi, curO - curE);
                if (i == 1) chmax(res, sumE + maxi);
                else chmax(res, sumE + diff.at(i-2) + maxi);
            }
        }
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
