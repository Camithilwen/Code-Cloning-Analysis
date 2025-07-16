#include <bits/stdc++.h>
using namespace std;
#define int long long   // <-----!!!!!!!!!!!!!!!!!!!

#define rep(i,n) for (int i=0;i<(n);++i)
#define rep2(i,a,b) for (int i=(a);i<(b);++i)
#define rrep(i,n) for (int i=(n)-1;i>=0;--i)
#define rrep2(i,a,b) for (int i=(a)-1;i>=b;--i)
#define chmin(a,b) (a)=min((a),(b));
#define chmax(a,b) (a)=max((a),(b));
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define printV(_v) cout<<(#_v)<<":";for(auto(_x):(_v)){cout<<" "<<(_x);}cout<<endl;
#define printVS(vs) cout<<(#vs)<<":"<<endl;for(auto(s):(vs)){cout<<(s)<< endl;}
#define printVV(vv) cout<<(#vv)<<":"<<endl;for(auto(v):(vv)){for(auto(x):(v)){cout<<" "<<(x);}cout<<endl;}
#define printP(p) cout<<(#p)<<(p).first<<" "<<(p).second<<endl;
#define printVP(vp) cout<<(#vp)<<":"<<endl;for(auto(p):(vp)){cout<<(p).first<<" "<<(p).second<<endl;}

inline void output(){ cout << endl; }
template<typename First, typename... Rest>
inline void output(const First& first, const Rest&... rest) {
    cout << first << " "; output(rest...);
}

using ll = long long;
using Pii = pair<int, int>;
using TUPLE = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
const int inf = 1ll << 60;
const int mod = 1e9 + 7;
using Graph = vector<vector<int>>;

class SCC {
private:
    const int n;
    vector<vector<int>> G;
    vector<vector<int>> rG;
    vector<int> vs;
    vector<bool> used;
    vector<int> cmp;
public:
    SCC(int _n) : n(_n), G(_n), rG(_n), used(_n), cmp(_n) {}
    void addEdge(int from, int to) {
        G[from].emplace_back(to);
        rG[to].emplace_back(from);
    }
    void dfs(int v) {
        used[v] = true;
        for (auto nxt : G[v]) if (!used[nxt]) dfs(nxt);
        vs.emplace_back(v);
    }
    void rdfs(int v, int k) {
        used[v] = true;
        cmp[v] = k;
        for (auto nxt : rG[v]) if (!used[nxt]) rdfs(nxt, k);
        vs.emplace_back(v);
    }
    int scc() {
        used.assign(n, false);
        rep(v, n) if (!used[v]) dfs(v);
        used.assign(n, false);
        int k = 0;
        for (int i = (int)vs.size() - 1; i >= 0; i--) {
            int v = vs[i];
            if (!used[v]) rdfs(v, k++);
        }
        return k;
    }
    bool same(int a, int b) {
        return cmp[a] == cmp[b];
    }
};

main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n, m;
    cin >> n >> m;
    SCC scc(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        scc.addEdge(a, b);
    }

    scc.scc();

    int q;
    cin >> q;
    rep(i, q) {
        int a, b;
        cin >> a >> b;
        cout << scc.same(a, b) << endl;
    }
}