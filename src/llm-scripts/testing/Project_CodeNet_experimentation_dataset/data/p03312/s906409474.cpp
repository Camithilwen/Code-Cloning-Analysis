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
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i=0; i<N; ++i) cin >> a[i];

    vector<ll> sum(N+1);
    for (int i=1; i<N+1; ++i) sum[i] = sum[i-1] + a[i-1];
    ll res = LINF;
    for (int i=2; i<N-1; ++i) {
        ll b, c, d, e;
        int ok = 0, ng = i;
        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (sum[mid] - sum[0] <= sum[i] - sum[mid]) ok = mid;
            else ng = mid;
        }
        b = sum[ok] - sum[0], c = sum[i] - sum[ok];
        if (ok + 1 < i) {
            ll tb = sum[ok+1] - sum[0], tc = sum[i] - sum[ok+1];
            if (tb - tc < c - b) {
                b = tb;
                c = tc;
            }
        }
        ok = i, ng = N;
        while (abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if (sum[mid] - sum[i] <= sum[N] - sum[mid]) ok = mid;
            else ng = mid;
        }
        d = sum[ok] - sum[i], e = sum[N] - sum[ok];
        if (ok + 1 < N) {
            ll td = sum[ok+1] - sum[i], te = sum[N] - sum[ok+1];
            if (td - te < e - d) {
                d = td;
                e = te;
            }
        }
        chmin(res, max({b, c, d, e}) - min({b, c, d, e}));
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();

    return 0;
}
