#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  int L;
  cin>>L;
  vector<vector<int>> dp(N,vector<int>(17));
  for(int j=0;j<17;j++){
    for(int i=0;i<N;i++){
      if(j==0){
        if(p[i]+L>=p[N-1]){
          dp[i][0]=N-1;
        }
        else{
          int b=lower_bound(p.begin(),p.end(),p[i]+L+1)-p.begin();
          dp[i][0]=b-1;
        }
      }
      else{
        dp[i][j]=dp[dp[i][j-1]][j-1];
      }
    }
  }
  int Q;
  cin>>Q;
  for(int l=0;l<Q;l++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    if(a>b){
      swap(a,b);
    }
    int Z=1;
    for(int i=16;i>=0;i--){
      if(dp[a][i]<b){
        Z+=(1<<i);
        a=dp[a][i];
      }
    }
    cout<<Z<<endl;
  }
}