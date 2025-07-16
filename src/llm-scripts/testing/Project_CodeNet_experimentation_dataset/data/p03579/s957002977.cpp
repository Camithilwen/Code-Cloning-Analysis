#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using vc = vector<char>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using stkll = vector<pll>;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
#define rep(i, n) for (ll i = 0; i < (n); i++)
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
#ifndef ONLINE_JUDGE
    #define debug(x) cerr << #x << ": " << x << endl;
#else
    #define debug(x)
#endif

vvll g;
vll color(110000, 0);
bool dfs(ll x, ll p = -1, ll c = 0) {
    color[x] = c;
    for(auto nx : g[x]) {
        if(color[nx] == c) return false;
        if(color[nx] ==0 && !dfs(nx, x, -c)) return false;
    }
    return true;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll n, m;
    cin >> n >> m;
    g = vvll(n);
    rep(i,m) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool is_bipartite = dfs(0, -1, 1);
    if(is_bipartite) {
        ll cw = 0, cb = 0;
        rep(i, n) {
            if(color[i] == 1) cw++;
            else cb++;
        }
        cout << cw * cb - m << endl;
    }
    else cout << n * (n-1) / 2 - m << endl;
}
