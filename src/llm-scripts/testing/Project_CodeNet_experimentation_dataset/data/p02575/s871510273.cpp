#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define put(x) std::cout << x << endl;
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;
 
// Segment tree
struct F { // min func
  typedef int TT;
  TT d;
  F(TT d=INF):d(d) {}
  F& operator+=(const F& f) {
    mins(d, f.d);
    return *this;
  }
  F operator+(const F& f) const { return F(*this) += f;}
};
struct seg {
  vector<F> d; int n;
  seg(){}
  seg(int mx) {
    n = 1; while (n < mx) n <<= 1;
    d = vector<F>(n<<1);
  }
  void upd(int i) { d[i] = d[i<<1]+d[i<<1|1];}
  F& operator[](int i) { return d[n+i];}
  void init() { for(int i=n-1;i;--i) upd(i);}
  void add(int i, F f) { for (i+=n,d[i]+=f,i>>=1;i;i>>=1) upd(i);}
  void set(int i, F f) { for (i+=n,d[i]=f,i>>=1;i;i>>=1) upd(i);}
  F get(int l, int r) {
    l += n; r += n;
    F lf, rf;
    while (l < r) {
      if (l&1) lf += d[l++];
      if (r&1) rf = d[--r] + rf;
      l >>= 1; r >>= 1;
    }
    return lf += rf;
  }
};

void Main()
{
    ll H, W;
    cin >> H >> W;

    vector<ll> A(H), B(H);
    rep(i, H) cin >> A[i] >> B[i];
    
    map<int, int> a;
    rep(i, W) a[i] = i;

    seg t(W+5);
    rep(i, W) t.add(i, F(0));
    
    rep(i, H) {
        ll l = A[i]-1;
        ll r = B[i];
        
        ll maxX = -1;
        for (auto it = a.lower_bound(l); it != a.end() && it->first < r; a.erase(it++)) {
            maxX = std::max(maxX, (ll)it->second);
            t.set(it->first, F(INF)); // invalid
        }

        if (r < W && maxX >= 0) {
            if (0 == a.count(r)) a[r] = -1;
            a[r] = max(a[r], (int)maxX);
            t.set(r, F(r - a[r]));
        }

        ll res = 1 + i + t.get(0, W).d; // get minimum
        if (res > INF) {
            put(-1);
        }
        else {
            put(res);
        }
    }

}
signed main(){ Main();return 0;}