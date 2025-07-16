#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("No"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

// Binary Indexed Tree
struct bit {
  typedef int TT;
  int n; vector<TT> d;
  bit() {}
  bit(int mx): n(mx), d(mx) {}
  void add(int i, TT x=1) {
    for (++i;i<n;i+=i&-i) d[i] += x;
  }
  TT sum(int i) {
    TT x = 0;
    for (++i;i;i-=i&-i) x += d[i];
    return x;
  }
};
//

int f(vi& s) {
  int n = sz(s);
  bit t(n+5);
  ll res = 0;
  rep(i,n) {
    res += i-t.sum(s[i]);
    t.add(s[i]);
  }
  return res&1;
}

int main() {
  int n;
  scanf("%d",&n);
  vvi na(3, vi(n));
  rep(i,3)rep(j,n) na[i][j] = in()-1;
  vi a, b;
  rep(i,n) {
    int x = na[0][i]/3;
    a.pb(x);
    rep(j,3) if (na[j][i]/3 != x) dame;
    if (na[1][i]%3 != 1) dame;
    b.pb(na[0][i]%3/2);
  }
  rep(i,n) if ((a[i]&1) != (i&1)) dame;
  vvi s(2);
  vi cnt(2);
  rep(i,n) {
    s[i&1].pb(a[i]/2);
    cnt[i&1] += b[i];
  }
  rep(i,2) {
    cnt[i^1] += f(s[i]);
  }
  rep(i,2) if (cnt[i]&1) dame;
  puts("Yes");
  return 0;
}





