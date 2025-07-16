#define BUG
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define fore(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define fort(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ford(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " /";
    __f(comma + 1, args...);
}
#endif

template <class T> bool mini(T& a, T b) { return a > b ? (a = b, 1) : 0; }
template <class T> bool maxi(T& a, T b) { return a < b ? (a = b, 1) : 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

const int INF = (int)1e9 + 7;

int main() {
#ifdef LOCAL
    freopen("CP.inp", "r", stdin);
//    freopen("CP.out", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h, w, a, b; cin >> h >> w >> a >> b;
    const int N = 2e5 + 3;
    const ll M = 1e9 + 7;
    auto mpow = [&](ll a, ll b) {
        ll res = 1;
        for (a %= M; b; a = a * a % M, b >>= 1) if (b & 1) res = res * a % M;
        return res;
    };
    vi fac(N), inv(N);
    fac[0] = 1;
    fore(i, 1, N) fac[i] = fac[i - 1] * i % M;
    inv[N - 1] = mpow(fac[N - 1], M - 2);
    ford(i, N - 2, 0) inv[i] = inv[i + 1] * (i + 1) % M;
    auto C = [&](int n, int k) {
        return fac[n] * inv[n - k] % M * inv[k] % M;
    };
    ll ans = 0;
    fort(i, b + 1, w) {
        (ans += C(h - a - 1 + i - 1, i - 1) * C(w - i + a - 1, w - i)) %= M;
    }
    cout << ans << '\n';
    return 0;
}
