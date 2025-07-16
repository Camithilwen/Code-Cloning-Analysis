#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n;
  cin>>n;
  int a[n];
  rep(i,0,n) cin>>a[i];
  ll dp[n+1][3];
  rep(i,0,3) dp[0][i]=0;
  dp[1][0]=a[0];
  dp[1][1]=0;
  dp[1][2]=0;
  rep(i,1,n){
    rep(j,0,3){
      if((i+1)%2==0){
        dp[i+1][0]=max(dp[i-1][0]+a[i],dp[i][0]);
        dp[i+1][1]=max(dp[i-1][1]+a[i],dp[i][1]);
        dp[i+1][2]=max(dp[i-1][2]+a[i],dp[i][2]);
      }
      else{
        dp[i+1][0]=dp[i-1][0]+a[i];
        dp[i+1][1]=max(dp[i-1][1]+a[i],dp[i][0]);
        dp[i+1][2]=max(dp[i-1][2]+a[i],dp[i][1]);
      }
    }
  }
  if(n%2==0) cout<<dp[n][0]<<endl;
  else cout<<dp[n][1]<<endl;
}