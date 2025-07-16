#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef
tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> orderedSet;

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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
}

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vi l(n, -1), r(n, -1);
    forn(i, n){
        if (i > 0) l[i] = i - 1;
        if (i + 1 < n) r[i] = i + 1;
    }
    int ans = n;
    queue<int> q;
    forn(i, n - 1){
        if (s[i] == 'S' && s[i + 1] == 'T') q.push(i);
    }
    while (!q.empty()){
        int i = q.front();
        q.pop();
        ans -= 2;
        int j = r[i], i1 = l[i], j1 = r[j];
        if (i1 == -1 || j1 == -1) continue;
        r[i1] = j1;
        l[j1] = i1;
        if (s[i1] == 'S' && s[j1] == 'T') q.push(i1);
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