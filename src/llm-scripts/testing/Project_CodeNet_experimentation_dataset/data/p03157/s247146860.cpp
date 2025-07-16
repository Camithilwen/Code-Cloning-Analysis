#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (ll i = 0; i < n; i++)
#define IREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define all(v) v.begin(), v.end()
#define SENTINEL 2000000000
#define NIL -1
using namespace std;
typedef long long ll;


const ll MAX = 510000;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template <class T>inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}

int h, w;
vector<string> v(400);
class UnionFind
{
public:
    vector<ll> par; // 各元の親を表す配列
    vector<ll> siz; // 素集合のサイズを表す配列(1 で初期化)
    vector<ll> siz_B;
    // Constructor
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1), siz_B(sz_,0)
    {
        for (ll i = 0; i < sz_; ++i)
            par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_)
    {
        par.resize(sz_);
        siz.assign(sz_, 1);
        siz_B.assign(sz_, 0);
        for (ll i = 0; i < sz_; ++i){
            par[i] = i;
            if (v[i / w][i % w] == '#')
            {
                siz_B[i]=1;
            }
        }
    }

    // Member Function
    // Find
    ll root(ll x)
    { // 根の検索
        while (par[x] != x)
        {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y])
            swap(x, y);
        siz[x] += siz[y];
        siz_B[x]+=siz_B[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y)
    { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x)
    { // 素集合のサイズ
        return siz[root(x)];
    }
    ll size_B(ll x){
        return siz_B[root(x)];
    }
};

int main()
{
    cin >> h >> w;
    REP(i,h){
        cin >> v[i];
    }
    UnionFind uf(h * w);
    uf.init(h*w);
    REP(i,h){
        REP(j,w){
            if(j!=w-1&&v[i][j]!=v[i][j+1]){
                uf.merge(i*w+j,i*w+j+1);
            }
            if(i!=h-1&&v[i][j]!=v[i+1][j]){
                uf.merge(i*w+j,(i+1)*w+j);
            }
        }
    }
    set<ll> ne;
    REP(i,h){
        REP(j,w){
            ne.insert(uf.root(i*w+j));
        }
    }
    ll ans=0;
    for(auto& k:ne){
        ans+=(uf.size(k)-uf.size_B(k))*(uf.size_B(k));
    }
    cout << ans << endl;
}
