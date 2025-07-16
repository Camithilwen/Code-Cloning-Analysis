#include<bits/stdc++.h>
using namespace std;
static const int64_t INF=100000000000000;
int main(){
  int N;cin>>N;
  vector<tuple<int64_t,int64_t,int64_t>>A(N);
  for(int i=0;i<N;i++){
  int64_t h,p;cin>>h>>p;
    tuple<int64_t,int64_t,int64_t>q(h+p,h,p);
    A.at(i)=q;
  }sort(A.begin(),A.end());
  vector<pair<int64_t,int64_t>>B(N);
  for(int i=0;i<N;i++){
  int64_t h=get<1>(A.at(i));
    int64_t p=get<2>(A.at(i));
    pair<int64_t,int64_t>q(h,p);
    B.at(i)=q;
  }vector<vector<int64_t>>dp(1+N,vector<int64_t>(1+N,INF));
  for(int i=0;i<=N;i++)dp[i][0]=0;
  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++){
      int64_t h=B[i-1].first;
      int64_t p=B[i-1].second;
    if(dp[i][j-1]!=INF){
    if(dp[i-1][j-1]<=h)
      dp[i][j]=min(dp[i-1][j-1]+p,dp[i-1][j]);
      else
        dp[i][j]=dp[i-1][j];
    
    }
    }int64_t ans=0;
  for(int j=N;0<=j;j--)
    if(dp[N][j]!=INF){ans=j;break;}
  cout<<ans<<endl;
  return 0;
}