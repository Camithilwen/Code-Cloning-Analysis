#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define int ll
const ll mod=998244353;
ll dp[333][99999]={0};
ll dp2[333][99999]={0};
ll ar[305]={0};
ll pow(ll x,ll y){
  if(y==0) return 1;
  ll res=pow(x,y/2);
  res*=res;
  res%=mod;
  if(y%2==1){
    res*=x;
    res%=mod;
  }
  return res;
}
signed main(){
  ll n,sum=0;
  cin>>n;
  dp[0][0]=1;
  dp2[0][0]=1;
  for(int i=0;i<n;i++){
    ll a;
    cin>>a;
    ar[i]=a;
    sum+=a;
  }
  for(int i=0;i<n;i++){
    ll a=ar[i];
    for(int j=0;j<98999;j++){
      dp[i+1][j]+=(dp[i][j]*2)%mod;
      dp[i+1][j+a]+=dp[i][j];
      dp[i+1][j]%=mod;
      dp[i+1][j+a]%=mod;

      dp2[i+1][j]+=dp2[i][j];
      dp2[i+1][j+a]+=dp2[i][j];
      dp2[i+1][j]%=mod;
      dp2[i+1][j+a]%=mod;
    }
  }

  ll ans=pow(3,n);
  for(ll i=(sum+1)/2;i<=sum;i++){
    ans+=mod-((dp[n][i]*3)%mod);
    ans%=mod;
  }
  if(sum%2==0) {
    ans+=(dp2[n][sum/2]*3)%mod;
    ans%=mod;
  }
  ans%=mod;
  cout<<ans<<endl;
}
