#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Segtree {
    int n;
    T e;
    vector<T> dat;
    typedef function<T(T a, T b)> Func;
    Func f;

    Segtree(){}
    Segtree(int n_input, Func f_input, T e_input){
        initialize(n_input, f_input, e_input);
    }
    void initialize(int n_input, Func f_input, T e_input){
        f = f_input;
        e = e_input;
        n = 1;
        while(n < n_input) n <<= 1;
        dat.resize(2*n-1, e);
    }

    void update(int k, T a){
        k += n - 1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1)/2;
            dat[k] = f(dat[2*k+1], dat[2*k+2]);
        }
    }

    T get(int k){
        return dat[k+n-1];
    }

    T between(int a, int b){
        return query(a, b+1, 0, 0, n);
    }

    T query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return e;
        if(a<=l && r<=b) return dat[k];
        T vl = query(a, b, 2*k+1, l, (l+r)/2);
        T vr = query(a, b, 2*k+2, (l+r)/2, r);
        return f(vl, vr);
    }
};

#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> sz;

    UnionFind(int n=0){
        if(n>0) initialize(n);
    }

    void initialize(int n){
        par.resize(n);
        sz.resize(n);
        for(int i=0; i<n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(sz[x] < sz[y]){
            par[x] = y;
            sz[y] += sz[x];
        }else{
            par[y] = x;
            sz[x] += sz[y];
        }
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }
};

int main(){
    int N;
    int64_t D, A[200000];
    cin >> N >> D;
    for(int i=0; i<N; i++) cin >> A[i];

    typedef pair<int64_t, int> P;
    const int64_t INF = 1e18;
    const P INFP = {INF, 0};
    Segtree<P> stL(N, [](P a, P b){ return min(a, b);}, INFP);
    Segtree<P> stR(N, [](P a, P b){ return min(a, b);}, INFP);

    vector<int> order;
    for(int i=0; i<N; i++) order.push_back(i);
    sort(order.begin(), order.end(), [&](int i, int j){ return A[i] < A[j];});
    vector<vector<int64_t>> edges;

    for(int i : order){
        auto p = stL.between(0, i);
        if(p != INFP){
            int64_t cost = p.first + A[i] - (N-i)*D;
            edges.push_back({cost, i, p.second});
        }
        p = stR.between(i, N-1);
        if(p != INFP){
            int64_t cost = p.first + A[i] - i*D;
            edges.push_back({cost, i, p.second});
        }
        stL.update(i, {A[i] + (N-i)*D, i});
        stR.update(i, {A[i] + i*D, i});
    }

    sort(edges.begin(), edges.end());
    UnionFind uf(N);
    int64_t ans = 0;
    for(auto& e : edges){
        if(!uf.same(e[1], e[2])){
            uf.unite(e[1], e[2]);
            ans += e[0];
        }
    }

    cout << ans << endl;
    return 0;
}