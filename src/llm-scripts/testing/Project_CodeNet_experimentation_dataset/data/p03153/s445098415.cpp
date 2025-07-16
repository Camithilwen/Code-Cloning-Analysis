#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct Union_Find_Tree{
    vector<int> par, rank, num;
    
    Union_Find_Tree(int N){
        par.assign(N, -1);
        rank.assign(N, 0);
        num.assign(N, 1);
    }
    
    int root(int x){
        if(par[x] < 0 || par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    void unite(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return;
        elif(rank[x] < rank[y]) par[x] = y, num[y] += num[x];
        else{
            par[y] = x, num[x] += num[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
    
    int size(int x) {return num[root(x)];}
    
    bool same(int x, int y){
        return root(x) == root(y);
    }
    
    void clear(){
        fill(par.begin(), par.end(), -1);
        fill(rank.begin(), rank.end(), 0);
        fill(num.begin(), num.end(), 1);
    }
};

template<typename Idempotent_Semigroup>
struct Sparse_Table{
    Idempotent_Semigroup ope(Idempotent_Semigroup a, Idempotent_Semigroup b){
        return min(a, b);
    }
    const int n;
    vector<vector<Idempotent_Semigroup>> st;
    vector<int> lookup;

    Sparse_Table(const vector<Idempotent_Semigroup> &table) : n(sz(table)){
        st.resize(n);
        rep(i, n) st[i].pb(table[i]);
        for(int k = 0; (1<<k) < n; k++){
            rep(i, n){
                if(i+(1<<k) < n) st[i].pb(ope(st[i][k], st[i+(1<<k)][k]));
                else st[i].pb(st[i][k]);
            }
        }
        lookup.resize(n+1);
        lookup[0] = -1;
        rep2(i, 1, n) lookup[i] = lookup[i/2]+1;
    }

    Idempotent_Semigroup query(int l, int r){
        if(l == r) return Idempotent_Semigroup(INF, -1);
        int k = lookup[r-l];
        return ope(st[l][k], st[r-(1<<k)][k]);
    }

    Idempotent_Semigroup operator [] (int i) {return st[i][0];}
};

int main(){
    int N; ll D;
    cin >> N >> D;
    ll A[N];
    rep(i, N) cin >> A[i];
    vector<pli> table1, table2;
    rep(i, N){
        table1.pb(pli(A[i]+D*i, i));
        table2.pb(pli(A[i]-D*i, i));
    }
    Sparse_Table<pli> st1(table1), st2(table2);
    Union_Find_Tree uft(N);
    vector<int> l(N), r(N);
    iota(all(l), 0), iota(all(r), 1);
    ll ans = 0;
    while(sz(l) > 1){
        int n = sz(l);
        rep(i, n){
            ll vl = st2.query(0, l[i]).first + st1.query(l[i], r[i]).first;
            ll vr = st1.query(r[i], N).first + st2.query(l[i], r[i]).first;
            if(vl < vr){
                int idl = st2.query(0, l[i]).second, idr = st1.query(l[i], r[i]).second;
                if(!uft.same(idl, idr)){
                    ans += A[idl]+A[idr]+D*(idr-idl);
                    uft.unite(idl, idr);
                }
            }
            else{
                int idl = st2.query(l[i], r[i]).second ,idr = st1.query(r[i], N).second;
                if(!uft.same(idl, idr)){
                    ans += A[idl]+A[idr]+D*(idr-idl);
                    uft.unite(idl, idr);
                }
            }
        }
        l.clear(), r.clear();
        int now = 0;
        while(now < N){
            l.pb(now), r.pb(now += uft.size(now));
        }
    }
    cout << ans << endl;
}