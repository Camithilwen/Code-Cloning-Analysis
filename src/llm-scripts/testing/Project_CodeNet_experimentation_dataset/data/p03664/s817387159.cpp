#include "bits/stdc++.h"
  
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector<vector<int>>edge(N,vector<int>(N));
  for(int i=0;i<M;i++){
    int a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    edge[a][b]=c;
    edge[b][a]=c;
  }
  vector<int>box(1<<N);
  for(int i=0;i<1<<N;i++){
    for(int j=0;j<N;j++){
      if((i>>j)&1){
      	for(int k=j+1;k<N;k++){
          if((i>>k)&1)box[i]+=edge[j][k];
        }
      }
    }
  }
  vector<vector<int>>dp(1<<N,vector<int>(N,-1e9));
  for(int i=1;i<1<<N;i+=2)dp[i][0]=box[i];
  for(int i=1;i<1<<N;i+=2){
    for(int j=0;j<N;j++){
      if(!((i>>j)&1))continue;
      int bag=(1<<N)-1-i;
      int c=bag;
      while(c>0){
        for(int k=1;k<N;k++){
          if(!edge[j][k])continue;
          if((c>>k)&1) dp[i|c][k]=max(dp[i|c][k],dp[i][j]+edge[j][k]+box[c]);
        }
        c--;
        c&=bag;
      }
    }
  }
  int ans=0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++)ans+=edge[i][j];
  }
  cout<<ans-dp.back().back()<<endl;
}
