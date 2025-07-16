#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e7;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

template<typename Mono,typename Ope>
struct LazySegmentTree{
    using F = function<Mono(Mono,Mono)>;
    using G = function<Mono(Mono,Ope)>;
    using H = function<Ope(Ope,Ope)>;
    int n,height;
    F f; G g; H h; Mono tu; Ope eu;
    vector<Mono> node;
    vector<Ope> lazy;

    LazySegmentTree(F f,G g,H h,Mono tu,Ope eu):f(f),g(g),h(h),tu(tu),eu(eu){}

    void init(vector<Mono> v){
        int n_ = (int)(v.size());
        n = 1;height = 0;
        while(n < n_) n <<= 1,++ height;
        node.assign(2*n,tu);
        lazy.assign(2*n,eu);
        for(int i=0;i<n_;i++) node[i+n] = v[i];
        for(int i=n-1;i>0;i--) node[i] = f(node[i<<1],node[i<<1|1]);
    }

    Mono eval(int k){
        return (lazy[k]==eu)?node[k]:g(node[k],lazy[k]);
    }

    void prop(int k){
        if(lazy[k]==eu) return;
        lazy[k<<1] = h(lazy[k<<1],lazy[k]);
        lazy[k<<1|1] = h(lazy[k<<1|1],lazy[k]);
        node[k] = eval(k);
        lazy[k] = eu;
    }

    void prop_above(int k){
        for(int i=height;i>0;i--) prop(k>>i);
    }

    void recalc_above(int k){
        while(k>0){
            k >>= 1;
            node[k] = f(eval(k<<1),eval(k<<1|1));
        }
    }

    void set_val(int k,Mono x){
        k += n;
        prop_above(k);
        node[k] = x;
        lazy[k] = eu;
        recalc_above(k);
    }

    void update(int l,int r,Ope x){
        if(l >= r) return;
        l += n;r += n-1;
        prop_above(l);
        prop_above(r);
        int a = l,b = r;
        ++ r;
        while(l < r){
            if(l&1) lazy[l] = h(lazy[l],x), ++l;
            if(r&1) --r, lazy[r] = h(lazy[r],x);
            l >>= 1;r >>= 1;
        }
        recalc_above(a);
        recalc_above(b);
    }

    Mono query(int l,int r){
        if(l >= r) return tu;
        l += n;r += n-1;
        prop_above(l);
        prop_above(r);++r;
        Mono vl = tu,vr = tu;
        while(l < r){
            if(l&1) vl = f(vl,eval(l)), ++l;
            if(r&1) --r, vr = f(eval(r),vr);
            l >>= 1;r >>= 1;
        }
        return f(vl,vr);
    }
    
};

struct my{
    int l,r; // 区間の左　区間の右
    ll x; // 区間のなかで配列i-a[i]の最小値 
};

int main(){
    auto f = [](my a,my b){
        if(a.l==-1) return b;
        else if(b.l==-1) return a;
        return my{a.l,b.r,min(a.x,b.x)};
    };
    auto g = [](my a,ll y){
        if(y==-1) return a;
        return my{a.l,a.r,a.l-y};
    };
    auto hh = [](ll x,ll y){ 
        if(y==-1) return x;
        return y;
    };
    LazySegmentTree<my,ll> seg(f,g,hh,my{-1,-1,LINF},-1);

    int h,w;
    cin >> h >> w;
    vector<int> a(h),b(h);
    rep(i,h) cin >> a[i] >> b[i];
    rep(i,h) --a[i],--b[i];

    vector<my> aa(w,my{-1,-1,LINF});
    ll res = LINF;
    rep(i,w){
        aa[i].l=i;
        aa[i].r=i+1;
        if(i<a[0]){
            aa[i].x=i;
            res=i;
        }else if(i<=b[0]){
            aa[i].x=res;
        }else{
            aa[i].x=i;
        }
    }
    rep(i,w){
        if(aa[i].x==LINF) continue;
        aa[i].x=i-aa[i].x;
    }

    /*
    rep(i,w){
        cout << aa[i].x << endl;
    }
    */

    seg.init(aa);

    vector<int> ans(h,-1);
    rep(i,h){
        ans[i] = seg.query(0,w).x + (i+1);

        if(i==h-1) continue;

        if(a[i+1]==0){
            seg.update(a[i+1],b[i+1]+1,-LINF);
        }else{
            ll now = (a[i+1]-1) - seg.query(a[i+1]-1,a[i+1]).x;
            seg.update(a[i+1],b[i+1]+1,now);
        }
    }
    rep(i,h){
        if(ans[i]>=LINF) cout << -1 << endl;
        else cout << ans[i] << endl;
    }
    return 0;
}