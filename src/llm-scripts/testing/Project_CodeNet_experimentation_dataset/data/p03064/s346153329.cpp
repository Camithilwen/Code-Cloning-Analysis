#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 998244353;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;

ll modadd(ll x, ll y) {
    return ((x + y) % mod + mod) % mod;
}

ll modminus(ll x, ll y) {
    return (x - y + mod) % mod;
}

ll multiply(ll x, ll y) {
    return (x % mod) * (y % mod) % mod;
}

ll modpower(ll x, ll y) {
    if (y == 0) {
        return 1;
    } else if (y == 1) {
        return x % mod;
    } else if (y % 2 == 0) {
        ll p = modpower(x, y / 2);
        return p * p % mod;
    } else {
        ll p = modpower (x, y / 2);
        return (p * p) % mod * (x % mod) % mod;
    }
}

ll dp[310][90010];
ll dpb[310][90010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll a[N];
    ll sum = 0;
    REP(i, 0, N) {
        cin >> a[i];
        sum += a[i];
    }
    dp[0][0] = 1;
    dpb[0][0] = 1;
    REP(i, 0, N) {
        REP(j, 0, 90000) {
            dp[i + 1][j] = modadd(dp[i + 1][j], multiply(dp[i][j], 2));
            dpb[i + 1][j] = modadd(dpb[i + 1][j], dpb[i][j]);
            if (j + a[i] <= 90000) {
                dp[i + 1][j + a[i]] = modadd(dp[i + 1][j + a[i]], dp[i][j]);
                dpb[i + 1][j + a[i]] = modadd(dpb[i + 1][j + a[i]], dpb[i][j]);
            }
        }
    }
    ll dis = 0;
    ll disa = 0;
    REP(i, (sum + 1) / 2, sum) {
        dis = modadd(dis, dp[N][i]);
    }
    dis = multiply(dis, 3);
    if (sum % 2 == 0) {
        disa = dpb[N][sum / 2];
    }
    disa = multiply(disa, 3);
    ll base = modadd(modpower(3, N), -3);
    ll ans = modadd(base, - modadd(dis, - disa));
    cout << ans << endl;
}
