#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const ld eps = 1e-9;
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;

template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

template<typename T>
struct edge {
    int src, to;
    T cost;
    // edge(int src, int to, T cost): src(src), to(to), cost(cost) {}
    // // G[i].push_back({src, to, cost}) requires no constructor
};

template<typename T>
using Graph = vector<vector<edge<T>>>;

template<typename T>
struct SCC {
    int sz, cnt, num;
    vi post, comp;
    vector<pair<int, int>> vp;
    vector<bool> sel;
    Graph<T> revg;

    SCC(int sz): sz(sz) {
        cnt = 0;
        num = 0;
        post.resize(sz, -1);
        comp.resize(sz, -1);
        sel.resize(sz, false);
        revg.resize(sz);
    }

    void build(const Graph<T> &g) {
        for(int i=0;i<sz;++i) {
            if(sel[i]) continue;
            sel[i] = true;
            dfs1(g, i);
        }

        rev(g, revg);

        for(int i=0;i<sz;++i) {
            vp.emplace_back(make_pair(post[i], i));
        }
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        sel.clear();
        sel.resize(sz, false);
        for(int i=0;i<sz;++i) {
            if(sel[vp[i].second]) continue;
            sel[vp[i].second] = true;
            comp[vp[i].second] = num;
            dfs2(revg, vp[i].second);
            num++;
        }
    }

    vi get_comp() {return comp;}

    Graph<T> build_graph(const Graph<T> &g) {
        build(g);
        vector<set<int>> s(sz);
        Graph<T> res(sz);
        for(int i=0;i<sz;++i) {
            for(int j=0;j<(int)(g[i].size());++j) {
                s[comp[i]].insert(comp[g[i][j].to]);
            }
        }
        for(int i=0;i<sz;++i) {
            for(auto j: s[i]) {
                if(i != j) res[i].push_back(edge<int>({i, j, 1}));
            }
        }
        return res;
    }

    void dfs1(const Graph<T> &g, int now) {
        for(int i=0;i<(int)(g[now].size());++i) {
            int nxt = g[now][i].to;
            if(sel[nxt]) continue;
            sel[nxt] = true;
            dfs1(g, nxt);
        }
        post[now] = cnt;
        cnt++;
    }

    void rev(const Graph<T> &g, Graph<T> &revg) {
        for(int i=0;i<sz;++i) {
            for(int j=0;j<(int)(g[i].size());++j) {
                revg[g[i][j].to].push_back({
                        g[i][j].to, g[i][j].src, g[i][j].cost});
            }
        }
    }

    void dfs2(const Graph<T> &revg, int now) {
        for(int i=0;i<(int)(revg[now].size());++i) {
            int nxt = revg[now][i].to;
            if(sel[nxt]) continue;
            sel[nxt] = true;
            comp[nxt] = num;
            dfs2(revg, nxt);
        }
    }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, m; cin >> n >> m;
  Graph<int> g(n);
  for(int i=0;i<m;++i) {
    int s, t; cin >> s >> t;
    g[s].push_back({s, t ,1});
  }

  SCC<int> scc(n);
  scc.build(g);
  auto comp = scc.get_comp();

  int q; cin >> q;
  for(int i=0;i<q;++i) {
    int u, v; cin >> u >> v;
    cout << (comp[u] == comp[v]) << endl;
  }
  

}

