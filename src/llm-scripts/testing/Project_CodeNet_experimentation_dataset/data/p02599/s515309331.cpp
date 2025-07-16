#include<cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define ALL(a) a.begin(), a.end()
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.sise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;
typedef vector<ll> vec;
typedef vector<vec> mat;

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

int main(){
    int n,q;
    cin >> n>> q;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> pi(n+1,-1);
    vector<vector<int>> ps(n);
    rep(i,n){
        int l = pi[a[i]];
        if (l != -1) ps[l].push_back(i);
        pi[a[i]] = i;
    }//赤矢印
    vector<vector<P>> qs(n);//青点
    rep(qi,q) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        qs[l].emplace_back(r,qi);
    }
    vector<int> ans(q);
    BIT<int> d(n);
    for (int x = n-1; x >= 0; --x) {//平面走査
        for (int y : ps[x]) d.add(y,1);
        for (P query : qs[x]) {
            int r = query.first, i = query.second;
            ans[i] = (r-x+1) - d.sum(r);
        }      
    }
    rep(i,q) cout << ans[i] << endl;
    return 0;
}