#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int mod=1e9+7;
const int INF=1001001001;

int dp[105][10];
int main() {
  int H,W,K;
  cin>>H>>W>>K;
  
  dp[0][0]=1;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(dp[i][j]==0){continue;}
      for(int s=0;s<(1<<W-1);s++){  
        vector<int>t(W-1);
        for(int k=0;k<W-1;k++){
          if((s>>k)&1){t[k]=1;}
        }
        bool ok=true;
        for(int k=0;k<W-2;k++){
          if(t[k]==1&&t[k+1]==1){ok=false;}
        }
        if(ok){
          if(j<W-1&&t[j]){(dp[i+1][j+1]+=dp[i][j])%=mod;}
          else if(j>0&&t[j-1]){(dp[i+1][j-1]+=dp[i][j])%=mod;}
          else{(dp[i+1][j]+=dp[i][j])%=mod;}
        }
      }
    }
  }
  
  cout<<dp[H][K-1]<<endl;
  return 0;  
}