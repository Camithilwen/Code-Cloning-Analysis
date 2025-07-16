#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define FORR(i, a, b) for(ll i = (a); i > (b); --i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define bitcnt __builtin_popcount
#define SZ(x) ((ll)(x).size())
#define fi first
#define se second
#define All(a) (a).begin(), (a).end()
template <typename T = long long> inline T IN() {
    T x;
    cin >> x;
    return (x);
}
inline void CIN() {}
template <class Head, class... Tail>
inline void CIN(Head &&head, Tail &&... tail) {
    cin >> head;
    CIN(move(tail)...);
}
#define CCIN(...)                                                              \
    char __VA_ARGS__;                                                          \
    CIN(__VA_ARGS__)
#define DCIN(...)                                                              \
    double __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    ll __VA_ARGS__;                                                            \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Yes(a) cout << (a ? "Yes" : "No") << "\n"
#define YES(a) cout << (a ? "YES" : "NO") << "\n"
#define Printv(v)                                                              \
    {                                                                          \
        FOREACH(x, v) { cout << x << " "; }                                    \
        cout << "\n";                                                          \
    }
template <typename T = string> inline void eputs(T s) {
    cout << s << "\n";
    exit(0);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}
template <typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using PQ = priority_queue<T>;

typedef long long ll;
typedef pair<ll, ll> PL;
typedef vector<PL> VPL;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<double> VD;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const double PI = atan(1.0) * 4.0;
// const int MOD = 998244353;
const ll LINF = 9e18;
const ll dx[] = {1, 0, -1, 0};
const ll dy[] = {0, 1, 0, -1};

void cinfast() {
    cin.tie(0);
    ios::sync_with_stdio(false);
}

ll S[2000][2000], sum[2020][2020], csum[2020][2020], rsum[2020][2020];

signed main() {
    cinfast();
    LCIN(N, M, Q);
    REP(i, N) REP(j, M) {
        CCIN(s);
        S[i][j] = (s == '1');
        sum[i + 1][j + 1] +=
            sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + S[i][j];
        if(j)
            rsum[i + 1][j + 1] += rsum[i + 1][j] + rsum[i][j + 1] - rsum[i][j] +
                                  (S[i][j] & S[i][j - 1]);
        if(i)
            csum[i + 1][j + 1] += csum[i + 1][j] + csum[i][j + 1] - csum[i][j] +
                                  (S[i][j] & S[i - 1][j]);
    }
    REP(i, Q) {
        LCIN(x1, y1, x2, y2);
        x1--, y1--, x2--, y2--;
        ll ans = 0;
        ans += sum[x2 + 1][y2 + 1] - sum[x1][y2 + 1] - sum[x2 + 1][y1] +
               sum[x1][y1];
        ans -= rsum[x2 + 1][y2 + 1] - rsum[x1][y2 + 1] - rsum[x2 + 1][y1 + 1] +
               rsum[x1][y1 + 1];
        ans -= csum[x2 + 1][y2 + 1] - csum[x1 + 1][y2 + 1] - csum[x2 + 1][y1] +
               csum[x1 + 1][y1];
        cout << ans << "\n";
    }
}
