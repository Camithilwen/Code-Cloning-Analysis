#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;

struct Edge {
    ll to;
    ll cost;
    Edge(ll t, ll c) {
        to = t;
        cost = c;
    }
};

typedef vector<vector<Edge>> Graph;

Graph G;
vector<int> seen;
vector<ll> d;

void dfs(ll node, ll value) {
    seen[node] = 1;
    d[node] = value;
    for (Edge e: G[node]) {
        if (seen[e.to] == 0) {
            dfs(e.to, value + e.cost);
        }
    }
}

void Main()
{
    ll n;
    cin >> n;

    vector<ll> a(n-1), b(n-1), c(n-1);
    rep(i, n-1) cin >> a[i] >> b[i] >> c[i];
    ll Q, K;
    cin >> Q >> K;
    vector<ll> x(Q), y(Q);
    rep(i, Q) cin >> x[i] >> y[i];

    G.assign(n, vector<Edge>());
    seen.assign(n, 0);
    d.assign(n, 0);
    rep(i, n-1) {
        G[b[i]-1].push_back(Edge{a[i]-1, c[i]});
        G[a[i]-1].push_back(Edge{b[i]-1, c[i]});
    }
    
    dfs(K - 1, 0);

    rep(i, Q) {
        ll res = d[x[i] -1] + d[y[i] - 1];
        put(res);
    }

}
signed main(){ Main();return 0;}