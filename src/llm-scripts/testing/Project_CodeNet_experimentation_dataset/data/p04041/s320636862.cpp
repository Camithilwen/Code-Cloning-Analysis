#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,x,y,z;
  cin>>n>>x>>y>>z;
  vector<vector<int>> dp(n+1,vector<int>((1<<(x+y+z-1)),0));
  int mask=(1ll<<(x+y+z-1))-1;
  int ng=(1<<(x+y+z-1))|(1<<(y+z-1))|(1<<(z-1));
  dp[0][0]=1;
  rep(i,n){
    rep(S,1<<(x+y+z-1)){
      if((S & ng)==ng) continue;
      FOR(j,1,11){
        int T=(S<<j) | (1<<(j-1));
        if((T & ng)==ng) continue;
        T&=mask;
        (dp[i+1][T]+=dp[i][S])%=mod;
      }
    }
  }
  ll ans=1;
  rep(i,n) (ans*=10)%=mod;
  rep(i,1<<(x+y+z-1)) (ans-=dp[n][i])%=mod;
  cout<<(ans+mod)%mod<<endl;
}