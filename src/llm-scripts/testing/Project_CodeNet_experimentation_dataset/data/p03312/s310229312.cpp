/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author alireza_kaviani
 */

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define Mp                          make_pair
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << " = " << x << endl
#define SZ(x)                       ll(x.size())
#define fast_io                     ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random                  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, ans = INF, A[MAXN], ps[MAXN];

void calc(ll l, ll m, ll r) {
    if (l - 0 + 1 <= 0 || m - l <= 0 || r - m <= 0 || n - 1 - r <= 0) return;
    ll s1 = ps[l], s2 = ps[m] - ps[l], s3 = ps[r] - ps[m], s4 = ps[n - 1] - ps[r];
    ans = min(ans, max({s1, s2, s3, s4}) - min({s1, s2, s3, s4}));
}

int main() {
    fast_io;

    cin >> n;
    for (ll i = 0; i < n; i++) cin >> A[i];
    partial_sum(A, A + n, ps);

    for (ll i = 1; i < n; i++) {
        ll m1 = ps[i] / 2, m2 = (ps[n - 1] - ps[i]) / 2;
        ll ind = lower_bound(ps, ps + i, m1) - ps;
        ll ind2 = lower_bound(ps + i + 1, ps + n, ps[i] + m2) - ps;

        calc(ind, i, ind2);
        calc(ind - 1, i, ind2);
        calc(ind, i, ind2 - 1);
        calc(ind - 1, i, ind2 - 1);
    }
    cout << ans << endl;

    return 0;
}
/*

*/
