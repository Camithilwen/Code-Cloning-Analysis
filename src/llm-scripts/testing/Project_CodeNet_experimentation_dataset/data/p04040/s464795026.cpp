#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>

using namespace std;
using namespace __gnu_pbds;

typedef
tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;

#define pb push_back
#define F first
#define S second
#define all(a) (a).begin(), (a).end()

#define for1(i0, l0, r0) for (int i0 = l0; i0 < r0; ++i0)
#define for2(i0, l0, r0) for (int i0 = l0; i0 <= r0; ++i0)
#define forn(i0, n0) for (int i0 = 0; i0 < n0; ++i0)
#define forn1(i0, n0) for (int i0 = 1; i0 < n0; ++i0)
#define forr(i0, n0) for (int i0 = n0; i0 >= 0; --i0)
#define forr1(i0, r0, l0) for (int i0 = r0; i0 > l0; --i0)
#define forr2(i0, r0, l0) for (int i0 = r0; i0 >= l0; --i0)

#define Sort(a) sort(all(a))
#define Reverse(a) reverse(all(a))
#define relaxMax(a, b) a = max(a, b)
#define relaxMin(a, b) a = min(a, b)

typedef long long ll;
typedef long double ld;
#define ui unsigned int
#define ull unsigned long long

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<string, string> pss;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;

typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pdd> vpdd;

typedef vector<vi> vvi;
typedef vector<vd> vvd;
typedef vector<vll> vvll;
typedef vector<vb> vvb;

#define vpss vector<pss>
#define vvs vector<vs>
#define vvpii vector<vpii>
#define vvpll vector<vpll>
#define vpt vector<pt>
#define vvvi vector<vvi>
#define vsi vector<set<int>>
#define ss second
#define ff first

#define printvi(arr) for (int x0 : arr) cout << x0 << ' '; cout << '\n';
#define printvll(arr) for (ll x0 : arr) cout << x0 << ' '; cout << '\n';
#define printpair(pair0) cout << pair0.F << ' ' << pair0.S << '\n';
#define printvp(arr) for (auto pair0 : arr) printpair(pair0);
#define initArray(arr, N0, X0) memset(arr, X0, N0 * sizeof(int))
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void init() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout.precision(16);
    //freopen("amusing.in", "r", stdin);
    //freopen("amusing.out", "w", stdout);
}

const int maxn = 2e5 + 1;
const int mod = 1e9 + 7;

vll fact(maxn);
vll invfact(maxn);

ll powmod(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        ll x = powmod(a, b / 2);
        return (x * x) % mod;
    }
    return (a * powmod(a, b - 1)) % mod;
}

void calcFactorials() {
    fact[0] = 1;
    forn1(i, maxn) fact[i] = (fact[i - 1] * (ll) i) % mod;
    forn(i, maxn) invfact[i] = powmod(fact[i], mod - 2);
}

ll cnk(int n, int k) {
    return ((fact[n] * invfact[k]) % mod) * invfact[n - k] % mod;
}

int h, w;

ll numberOfWays(int x, int y){
    int dx1 = x - 1, dy1 = y - 1;
    int dx2 = h - x - 1, dy2 = w - y;
    return (cnk(dx1 + dy1, dx1) * cnk(dx2 + dy2, dx2)) % mod;
}

void solve() {
    calcFactorials();
    int a, b;
    cin >> h >> w >> a >> b;
    ll ans = 0;
    for2(i, b + 1, w){
        ans += numberOfWays(h - a, i);
        ans %= mod;
    }
    cout << ans << '\n';
}

bool multitest = false;

int main() {
    init();
    int t = 1;
    if (multitest) cin >> t;
    forn(i, t) solve();
}