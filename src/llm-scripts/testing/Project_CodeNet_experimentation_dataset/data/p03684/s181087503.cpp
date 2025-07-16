#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
const long long LINF = 1e18;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define FOREACH(x,a) for(auto& (x) : (a) )
typedef long long ll;
using namespace std;
typedef pair<ll, ll> P; // pair(coordinate, index)

struct Edge {
    ll from, to, cost;
    Edge(){}
    Edge(ll from, ll to, ll cost):from(from),to(to),cost(cost){}
};

bool comp(const Edge &e1, const Edge &e2) {
    return e1.cost<e2.cost;
}

class union_find {
private:
    vector<ll> par;
    vector<ll> ran;
    vector<ll> m_size;
public:
    union_find(int n);
    int find(int x);
    void unite(int x, int y);
    bool same(int x, int y);
    ll size(int x);
};

union_find::union_find(int n){
    par.resize(n);
    iota(par.begin(), par.end(), 0);
    ran.resize(n, 0);
    m_size.resize(n, 1);
};

int union_find::find(int x) {
    if (par[x] == x) return x;
    else return par[x] = find(par[x]);
};

void union_find::unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (ran[x] < ran[y]) swap(x,y);
    par[y] = x;
    m_size[x] += m_size[y];
    if (ran[x]==ran[y]) ran[x]++;
};

ll union_find::size(int x) {
    return m_size[find(x)];
}

bool union_find::same(int x, int y) {
    return (find(x) == find(y));
};


vector<Edge> g;

int V;

ll kruskal() {
    sort(g.begin(), g.end(), comp);
    union_find uf(V+1);
    ll res = 0ll;
    for (auto &&e: g) {
        if (!uf.same(e.from,e.to)) {
            uf.unite(e.from,e.to);
            res+=e.cost;
        }
    }
    return res;
}

int main(int argc, char const *argv[]) {
    cin>>V;
    vector<P> X, Y;

    rep(i,V) {
        ll x,y; cin>>x>>y;
        X.emplace_back(x,i); Y.emplace_back(y,i);
    }

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    rep(i,V-1) {
        ll from = X[i].second; ll to = X[i+1].second;
        ll cost = X[i+1].first-X[i].first;
        g.emplace_back(from,to,cost);
        from = Y[i].second; to = Y[i+1].second;
        cost = Y[i+1].first-Y[i].first;
        g.emplace_back(from,to,cost);
    }

    cout << kruskal() << endl;

    return 0;
}
