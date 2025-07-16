#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9+10;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

ll n,m,v,p;
vll a;
vll sum;

// mid ... 添え字 => a[mid]は採用されるか
// midが採用される 
// midがp以内である(n-mid+<=p) => ok
// midがpより後である =>
// midを+1, 0~mid-1を+1する。残り v-(mid+1)
// midがp番目になるには2つ条件が必要
// - v-(mid+1)<=p-1
// - a[mid]+m>=a[n-p (p番目)]
bool isOk(ll mid){
  if(n-mid<=p) return 1;
  
  ll rem=v-(mid+1)-(p-1); // midを選ぶ上で1人が影響のない分を投票した残り
  
  if(rem<=0){
    if(a[mid]+m>=a[n-p]) return 1;
  }else{
    ll cnt=(n-(p-1))-(mid+1);
    ll d=(sum[n-(p-1)]-sum[mid+1]);
    ll x=(a[mid]+m)*cnt-d;
    // cout<<mid<<' '<<d<<' '<<x<<' '<<rem<<' '<<cnt<<endl;
    if(x>=rem*m && a[mid]+m>=a[n-p]) return 1;
  }
  return 0;
}


signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  cin>>n>>m>>v>>p;
  
  a.resize(n);
  rep(i,n) cin>>a[i];
  vsort(a);
  sum.resize(n+1);
  rep(i,n) sum[i+1]=sum[i]+a[i];
  
  // rep(i,n) cout<<a[i]<<' ';
  // cout<<endl;
  
  ll ng=-1, ok=n-1;
  while(abs(ok-ng)>1){
    ll mid=(ok+ng)/2;
    if(isOk(mid)) ok=mid;
    else ng=mid;
  }
  ll ans=n-ok;
  
  cout<<ans<<endl;
}