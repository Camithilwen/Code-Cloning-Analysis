#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repo(i,n) for(int i = 1; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define np next_permutation
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define modo 1000000007
#define mod 998244353
#define pi acos(-1.0)
const ll INF = 1LL<<61;
template<class T>bool chmax(T &a, const T &b) { 
  if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) {
  if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll jou(ll N, ll P){if(P==0) return 1;
  if(P%2==0){ll t = jou(N, P/2);return t*t % mod;
  }return (N * jou(N, P-1)) % mod;}  //jou(n,mod-2)で逆元
//intの最大値2147483647 ≒ 2×10^9
//long longの最大値9223372036854775807 ≒ 9×10^18
//'大文字'+=32;    で小文字に
//  cout << fixed << setprecision (20);   小数点以下2０桁まで
//実行時間制約2秒では２×10^8回くらいまで計算できる




int main(){
  int n;
  cin>>n;

  int x;
  cin>>x;
  if(x!=0){
    cout << 0 << endl;
    return 0;
  }

  vector<ll> p(n);
  rep(i,n-1){
    int y;
    cin>>y;
    if(y==0){
      cout << 0 << endl;
      return 0;
    }
    p[y]++;
  }

  repo(i,n-1){
    if(p[i]==0&&p[i+1]!=0){
      cout << 0 << endl;
      return 0;
    }
  }

  ll ans=1;
  for(int i=1;i<n-1;i++){
    ans*=jou(p[i],p[i+1]);
    ans%=998244353ll;
  }

  cout << ans << endl;
}