#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
using namespace std;

#define rep(i,a,n) for(int i=a; i<n; i++)
#define repr(i,a,n) for(int i=a; i>=n; i--)
#define pb(a) push_back(a)
#define fr first
#define sc second
#define INF INT_MAX

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))

typedef vector<int> VI;
typedef vector<VI> MAT;
typedef pair<int, int> pii;
typedef long long int ll;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int const MOD = 1000000007;

// ????????¨???????????????????¨???????????§???????
struct Edge {
    int from, to, cost;
    Edge(int f, int s, int d) : from(f), to(s), cost(d) {}
};

// 1??????????????????????????????????????±????????????????????????????????? vector
// Edges????????????????????????????????????????????°??????????????????
typedef vector<Edge> Edges;

// ???????????±??????????????? vector
// Graph??????????????????????????°?????????????????§??? V ??§?????????
typedef vector<Edges> Graph;

// union-find??¨
int uf[100010];
int rank[100010];

// ?????????
void init(int n) {
    rep(i,0,n) {
        uf[i] = i;
        rank[i] = 0;
    }
}

// find (??¨??????????±???????)
int find(int x) {
    if(uf[x] == x) return x;
    else return uf[x] = find(uf[x]);
}

// x ??¨ y ????±??????????????????????
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rank[x] < rank[y]) uf[x] = y;

    else {
        uf[y] = x;
        if(rank[x] == rank[y]) rank[x]++;
    }
}

// x ??¨ y ???????????????????±???????????????????
bool same(int x, int y) {
    return find(x) == find(y);
}

bool comp(const Edge &e1, const Edge &e2) {
    return e1.cost < e2.cost;
}

int kruskal(Graph &G) {
    int V = G.size();
    vector<Edge> es;
    rep(i,0,V) rep(j,0,G[i].size()) es.push_back(G[i][j]);
    int E = es.size();
    sort(es.begin(), es.end(), comp);
    init(V); int res = 0;
    for(int i=0; i<E; i++) {
        Edge e = es[i];
        if(!same(e.from, e.to)) {
            unite(e.from, e.to);
            res += e.cost;
        }
    }
    return res;
}

namespace std {
    bool operator<(const P a, const P b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    Graph G(V);
    int s, t, d;
    rep(i,0,E) {
        cin >> s >> t >> d;
        G[s].push_back(Edge(s,t,d));
        G[t].push_back(Edge(t,s,d)); // ????????°??????????????§
    }

    int ans = kruskal(G);
    cout << ans << endl;
    return 0;
}