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

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll ngcd(vector<ll> a) {
  ll res = a[0];
  for(ll i=1; i<a.size() && res!=1; i++) res = gcd(a[i], res);
  return res;
}
ll nlcm(vector<ll> a){
  ll res = a[0];
  for(ll i=1; i<a.size(); i++) res = lcm(a[i], res);
  return res;
}
bool is_prime(ll n) {
  if(n < 2) return false;
  for (ll i = 2; i * i <= n; i++) if (n % i == 0) return false;
  return true;
}
ll digsum(ll n) {
  ll res=0;
  while(n) res += n%10, n /= 10;
  return res;
}
ll digcnt(ll n){
  ll res=0;
  while(n) res++, n /= 10;
  return res;
}
vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}
map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) ++res[i], n /= i;
  }
  if (n != 1) res[n] = 1;
  return res;
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  ll n,m; cin>>n>>m;
  auto v=divisor(m);
  
  ll ans=1;
  for(auto e: v){
    if(m-e*(n-1)>0 && (m-e*(n-1))%e==0) chmax(ans,e);
  }
  cout<<ans<<endl;
}