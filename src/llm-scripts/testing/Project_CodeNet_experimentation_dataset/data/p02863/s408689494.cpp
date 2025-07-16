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


int main(){
  int n,t;
  cin >> n >> t;
  vector<P> a(n);
  rep(i,n){
    cin >> a[i].F >> a[i].S;
  }
  sort(a.begin(),a.end());

  vector<vector<ll>> dp(3010, vector<ll>(6010,0));
  rep(i,n)rep(j,6005){
    dp[i+1][j] = dp[i][j];
    if(j-a[i].F>=0 && j-a[i].F<t){
      dp[i+1][j] = max(dp[i+1][j], dp[i][j-a[i].F] + a[i].S);
    }
  }
  ll ans = 0;
  rep(i,6005){
    ans = max(ans, dp[n][i]);
  }
  cout << ans << ln;
  return 0;
}