#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln =  '\n';

const int mx=100010;
const ll mod=1e9+7;

#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

vector<vector<ll>> a(20, vector<ll>(20,0));
vector<ll> dp((1<<18),-longinf);
int n;

ll rec(ll x){
  if(dp[x]!=-longinf) return dp[x];
  ll cur = 0;
  rep(i,n)rep(j,i)if(bit(x,i) && bit(x,j)){ cur += a[i][j]; }
  for(ll i=(1<<n)-1; i>=0; i--){
    i &= x; //x bubun syugo //https://primenumber.hatenadiary.jp/entry/2016/12/01/000000
    if(i==x || i==0) continue;
    cur = max(cur, rec(i) + rec(i^x));
  }
  return dp[x] = cur;
}

int main(){
  cin >> n;
  rep(i,n)rep(j,n){
    cin >> a[i][j];
  }
  ll ans = rec((1<<n)-1);
  cout << ans << ln;
  return 0;
}