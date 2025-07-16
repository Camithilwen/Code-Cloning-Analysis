#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(a, b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define show(x) cout <<#x<<" = "<<(x)<<endl
#define spair(p) cout <<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout <<" "<<kbrni;cout<<endl

using namespace std;

typedef pair<int,int>P;

template<class V> class segtree {
private:
    int n;
    vector<V> node, lazy;
    vector<bool> lazyFlag;

public:
    segtree(vector<V> v) {
        int sz = (int)v.size();
        n = 1;
        while(n < sz){
            n *= 2;
        }
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        lazyFlag.resize(2*n-1,false);
        rep(i,sz){
            node[i+n-1] = v[i];
        }
        for(int i=n-2; i>=0; i--){
            node[i] = min(node[i*2+1],node[i*2+2]);
        }
    }
    void eval(int k, int l, int r) {
        if(lazyFlag[k]) {
            node[k] = lazy[k];
            if(r - l > 1) {
                lazy[k*2+1] = lazy[k*2+2] = lazy[k];
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazyFlag[k] = false;
        }
    }
    void range(int a, int b, V x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a){
            return;
        }
        if(a <= l && r <= b) {
            lazy[k] = x;
            lazyFlag[k] = true;
            eval(k, l, r);
        }
        else {
            range(a, b, x, 2*k+1, l, (l+r)/2);
            range(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1],node[2*k+2]);
        }
    }
    V query(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a){
            return INT_MAX;
        }
        if(a <= l && r <= b){
            return node[k];
        }
        V vl = query(a, b, 2*k+1, l, (l+r)/2);
        V vr = query(a, b, 2*k+2, (l+r)/2, r);
        return min(vl,vr);
    }
};

int main()
{
    int n,q;
    cin >> n >> q;
    segtree<int> sg(vector<int>(n,INT_MAX));
    rep(i,q){
        int k;
        cin >> k;
        if(k){
            int x;
            cin >> x;
            cout << sg.query(x,x+1) << "\n";
        }else{
            int x,y,z;
            cin >> x >> y >> z;
            sg.range(x,y+1,z);
        }
    }
}