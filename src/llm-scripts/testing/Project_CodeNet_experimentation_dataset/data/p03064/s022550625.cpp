#include<bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> using vt = vector<T>;
template<class T> using vvt = vector<vt<T>>;
template<class T> using ttt = tuple<T,T>;
using tii = tuple<int,int>;
using tiii = tuple<int,int,int>;
using vi = vector<int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
#define FST first
#define SEC second
#define DEB cerr<<"!"<<endl
#define SHOW(a,b) cerr<<(a)<<" "<<(b)<<endl
#define DIV 998244353
const int INF = (INT_MAX/2);
const ll LLINF = (LLONG_MAX/2);
const double eps = 1e-10;
//const double PI = M_PI;  
inline ll pow(ll x,ll n,ll m){ll r=1;while(n>0){if((n&1)==1)r=r*x%m;x=x*x%m;n>>=1;}return r%m;}
inline ll lcm(ll d1, ll d2){return d1 / __gcd(d1, d2) * d2;}

/* Coding space */
ll dp[301][100000] = {};
ll dp2[301][100000] = {};
int main(){
  int n; cin >> n;
  ll sum = 0;
  vt<ll> in(n); rep(i,n)  cin >> in[i], sum += in[i];
  ll ans = pow(3,n,DIV);
  dp[0][0] = dp2[0][0] = 1;
  rep(i,n){
    rep(j,100000){
      dp[i+1][j+in[i]] += dp[i][j];
      dp[i+1][j] += dp[i][j]*2;
      dp[i+1][j] %= DIV;
      dp[i+1][j+in[i]] %= DIV;
      
      dp2[i+1][j+in[i]] += dp2[i][j];
      dp2[i+1][j] += dp2[i][j];
      dp2[i+1][j] %= DIV;
      dp2[i+1][j+in[i]] %= DIV;
    }
  }
  //ans_d -= (cnt)*(cnt-1)/2;
  ll ans_d = 0;
  ll cnt = 0;
  rep(i,100000){
    if(i >= (sum+1)/2)ans_d += dp[n][i];
    ans_d %= DIV;
  }
  if(sum%2 == 0)cnt += dp2[n][sum/2], cnt %= DIV;
  cerr << ans << " " << ans_d << " " << cnt << endl;
  ans += 10LL * DIV - 3*ans_d;
  ans %= DIV;
  cout << (ans + 3*cnt)%DIV<< endl;
}