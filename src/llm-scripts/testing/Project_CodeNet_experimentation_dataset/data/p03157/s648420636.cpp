#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    
    UnionFind(int n = 1) {
        init(n);
    }
    
    void init(int n = 1) {
        par.resize(n); rank.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0;
    }
    
    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll h, w;
    cin>>h>>w;
    vector<string> grid(h);
    cin>>grid;

    UnionFind ds(h * w);
    rep(i, h) rep(j, w) {
        if (i - 1 >= 0 && grid[i][j] != grid[i - 1][j]) ds.merge(i * w + j, (i - 1) * w + j);
        if (i + 1 < h && grid[i][j] != grid[i + 1][j]) ds.merge(i * w + j, (i + 1) * w + j);
        if (j + 1 < w && grid[i][j] != grid[i][j + 1]) ds.merge(i * w + j, i * w + j + 1);
        if (j - 1 >= 0 && grid[i][j] != grid[i][j - 1]) ds.merge(i * w + j, i * w + j - 1);
    }

    vl bs(h * w);
    vl ws(h * w);
    rep(i, h) rep(j, w) {
        if (grid[i][j] == '#') bs[ds.root(i * w + j)]++;
        else ws[ds.root(i * w + j)]++;
    }
    ll ans = 0;
    rep(i, h * w) {
        ans += bs[i] * ws[i];
    }
    cout<<ans<<endl;
}