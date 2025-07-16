#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

const ll INF = TEN(18);

int main() {
    int n;
    cin >> n;
    V<int> A(n);
    rep(i, n) cin >> A[i];
    using pll = pair<ll, ll>;
    V<pll> vl(n, mp(-INF, INF)), vr(n, mp(-INF, INF));

    auto ch = [&](pll& a, pll b) {
        if (abs(a.se - a.fi) > abs(b.fi - b.se)) {
            a = b;
        }
        return;
    };

    rep(t, 2) {
        ll s = 0;
        V<ll> acm;
        V<pll>& vec = (t == 0 ? vl : vr);

        rep(i, n) {
            s += A[i];
            acm.pb(s);
            if (i) {
                int p = lower_bound(ALL(acm), s / 2) - acm.begin();
                if (p == i) --p;
                auto x = mp(acm[p], s - acm[p]);
                ch(vec[i], x);
                --p;
                if (p >= 0) {
                    auto x = mp(acm[p], s - acm[p]);
                    ch(vec[i], x);
                }
            }
        }
        reverse(ALL(A));
    }

    ll ans = INF;
    for (int i = 1; i < n - 2; ++i) {
        auto p = vl[i], q = vr[n - i - 2];
        V<ll> v = {p.fi, p.se, q.fi, q.se};
        sort(ALL(v));
        chmin(ans, v.back() - v[0]);
    }
    cout << ans << endl;

    return 0;
}