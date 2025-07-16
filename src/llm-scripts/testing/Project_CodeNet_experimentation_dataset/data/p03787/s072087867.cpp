#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int N,M;
int nor, bip, sing, done[MX];
ll ans;
vi adj[MX];
bool ok = 1;

ll sq(ll x) { return x*x; };

void dfs(int x, int y) {
    if (done[x]) {
        if (done[x] != y) ok = 0;
        return;
    }
    // cout << "HUH " << x << "\n";
    done[x] = y;
    for (int i: adj[x]) dfs(i,y^3);
}

void solve(int x) {
    if (sz(adj[x]) == 0) {
        sing ++;
        return;
    }
    ok = 1;
    dfs(x,1); // cout << "OOPS " << x << "\n";
    if (ok) bip ++;
    else nor ++;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    F0R(i,M) {
        int u,v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }
    FOR(i,1,N+1) if (!done[i]) {
        //cout << i << "\n";
        solve(i);
    }
    //cout << nor << " " << bip << " " << sing << "\n";
    F0R(i,sing) {
        ans += 2*N-1; N --;
    }
    //cout << ans << "\n";
    ans += sq(bip);
    ans += sq(nor+bip);
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS