#include <iostream>
#include <iomanip>
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
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

// ?§?????????¨????????¨???????????????????¨???????????§???????
template <typename T>
struct Edge {
    int from, to;
    T cost;
    Edge(int s, T d) : to(s), cost(d) {}
    Edge(int f, int s, T d) : from(f), to(s), cost(d) {}

    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
    bool operator>(const Edge &e) const {
        return cost > e.cost;
    }
};

template <typename T>
using Graph = vector< vector< Edge<T> > >;

// ??¢??????????±??????? (artPoints)
// ???????±??????? (bridges)

// ??¢?????????????????????????????¨????????£?????§???????????£???????????????????????????????????¨
// ????????????????????????????????£?????§???????????£????????????????????????????????¨

template <typename T>
struct graphLink {
    vector<int> ord, low, parent;
    vector< vector< Edge<T> > > G;
    vector< pair<int, int> > brdgs;
    int cnt, v;

    // init
    graphLink(int _n) : ord(_n, -1), low(_n, 0),
                        parent(_n, -1), G(_n), cnt(0), v(_n) {}

    bool is_bridge(int x, int y) {
        if(ord[x] > ord[y]) swap(x, y);
        return ord[x] < low[y];
    }

    // example: dfs(0);
    void dfs(int cur, int prev=-1) {
        low[cur] = cnt;
        ord[cur] = cnt++;

        for(auto x : G[cur]) {
            if(ord[x.to] < 0) {
                parent[x.to] = cur;
                dfs(x.to, cur);

                low[cur] = min(low[cur], low[x.to]);
            }
            else if(x.to != prev) {
                low[cur] = min(low[cur], ord[x.to]);
            }
            if(cur != x.to && is_bridge(cur, x.to)) {
                brdgs.emplace_back(make_pair(cur, x.to));
            }
        }
    }

    set<int> artPoints(int root) {
        set<int> se;
        int num = 0;
        rep(i,0,v) {
            // printf("%lld: %lld %lld\n", i, ord[parent[i]], low[i]);
            if(parent[i] < 0) continue;
            if(parent[i] == root) num++;
            else if(ord[parent[i]] <= low[i]) se.insert(parent[i]);
        }
        if(num >= 2) se.insert(0);
        return se;
    }

    // vp ??? ???????????±?????????
    set<pii> bridges(vector<pii> vp) {
        set<pii> se;
        rep(i,0,vp.size()) {
            if(ord[vp[i].first] < low[vp[i].second] || ord[vp[i].second] < low[vp[i].first]) {
                // se.insert(vp[i]);

                // ????????? (????????????????????????????????°???????????????????????§??\??????)
                int mi = min(vp[i].first, vp[i].second);
                int ma = max(vp[i].first, vp[i].second);
                se.insert(pii(mi, ma));
            }
        }
        return se;
    }
};

signed main() {
    int V, E; cin >> V >> E;
    graphLink<int> gr(V);
    rep(i,0,E) {
        int s, t; cin >> s >> t;
        gr.G[s].push_back(Edge<int>(t, 1));
        gr.G[t].push_back(Edge<int>(s, 1));
    }
    gr.dfs(0);
    set<int> ans = gr.artPoints(0);
    for(auto x : ans) cout << x << endl;
}