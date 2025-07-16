#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

ll dp[11][210000];
const int INF=1e9;

int main() {
  ll d,g;
  cin>>d>>g;
  g/=100;
  
  vector<int> P(d+1),C(d+1);
  int x;
  rep(i,d){
    cin>>P[i+1]>>x;
    C[i+1]=x/100;
  }
  
  rep(i,11){
    rep(j,210000) dp[i][j]=INF;
  }
  dp[0][0]=0;
  
  for(int i=1;i<=d;i++){
    for(int j=0;j<=g+20000;j++){
      for(int k=0;k<P[i];k++){
        if(j-k*i<0) continue;
        dp[i][j]=min(dp[i][j],dp[i-1][j-k*i]+k);
      }
      if(j-P[i]*i-C[i]<0) continue;
      dp[i][j]=min(dp[i][j],dp[i-1][j-P[i]*i-C[i]]+P[i]);
    }
  }
  ll ans=INF;
  for(int i=g;i<=g+20000;i++){
    ans=min(ans,dp[d][i]);
  }
  cout<<ans<<endl;

  return 0;
}