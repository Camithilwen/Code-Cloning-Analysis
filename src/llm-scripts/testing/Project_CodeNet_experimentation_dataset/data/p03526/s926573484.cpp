#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

struct int_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct pair_hash {
    size_t operator()(pii x) const {
        return int_hash{}(x.first) ^ (int_hash{}(x.second) << 16);
    }
};

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<cd> vcd;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef unordered_map<int, int, int_hash> umpii;
typedef unordered_map<ll, ll, int_hash> umpll;
typedef unordered_set<int, int_hash> usi;
typedef unordered_set<ll, int_hash> usll;
typedef unordered_set<pii, pair_hash> uspii;
typedef queue<int> qi;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = numeric_limits<int>::max();
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vpii v(n, {0, 0}); 
    F0R(i, n) {
        cin >> v[i].f;
        cin >> v[i].s;
    }

    sort(v.begin(), v.end(), [](const pii &p1, const pii &p2){ return p1.f + p1.s < p2.f + p2.s; });
    vvi dp(n + 1, vi(n + 1, inf));
    dp[0][0] = 0;
    int ans = 0;
    F0R(i, n) {
        F0R(j, i + 1) {
            dp[i + 1][j + 1] = min(dp[i][j + 1], v[i].f >= dp[i][j] ? dp[i][j] + v[i].s : inf);
            ans = max(ans, dp[i + 1][j + 1] == inf ? 0 : j + 1);
        }
    }

    cout << ans << endl;
}
