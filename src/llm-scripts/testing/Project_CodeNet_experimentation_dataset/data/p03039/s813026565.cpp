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

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

ll modpow(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    (a *= a) %= MOD;
    n >>= 1;
  }
  return res;
}

const ll maxf = 10000000;
ll fact[maxf+5];
ll ifact[maxf+5];

void fact_init(){
  fact[0] = 1;
  for(ll i=1; i<=maxf; i++) fact[i] = (fact[i-1] * i) % MOD;
  ifact[maxf]=modpow(fact[maxf],MOD-2);
  for(ll i=maxf; i>=1; i--) ifact[i-1] = (ifact[i] * i) % MOD;
}

ll comb(ll n, ll r){
  if(n<r || n<0 || r<0) return 0;
  if(fact[0] == 0) fact_init();
  return ((fact[n] * ifact[n-r]) % MOD * ifact[r]) % MOD;
}

ll naive_comb(ll n, ll r){
  ll res = 1;
  for (ll i = n; i > n - r; i--) res = res * i % MOD;
  for (ll i = 1; i <= r; i++) res = (res * modpow(i, MOD-2)) % MOD;
  return res;
}

// 参考: https://drken1215.hatenablog.com/entry/2019/06/15/111500

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll n,m,k; cin>>n>>m>>k;
  ll sum=0;
  // y軸方向の取りうる距離
  for(ll i=0; i<=n-1; i++){
    // x軸方向の取りうる距離
    for(ll j=0; j<=m-1; j++){
      // y軸方向の距離がiのとき、選べるマスの組数はn-i通り (x軸も同様に考える)
      // (配置する駒同士は区別されない)
      ll tmp=(n-i)*(m-j)%MOD*(i+j)%MOD;
      // i,jがともに0でないならば、そのような駒の配置の仕方は2パターン存在する
      // 例えば (x1,y1), (x2,y2) が i,j を成すなら、(x1,y2), (x2,y1) も同様に i,j を成す
      // 互いに区別される配置で同じ i,j の組合せがもう一組作れるので、i,j がともに0でない場合は2倍する
      if(i!=0 && j!=0) (tmp*=2)%=MOD;
      (sum+=tmp)%=MOD;
    }
  }
  ll ans=(sum*comb(n*m-2,k-2))%MOD;
  cout<<ans<<endl;
}