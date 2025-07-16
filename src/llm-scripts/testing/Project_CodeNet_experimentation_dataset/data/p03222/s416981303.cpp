#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1000000007;
int H,W,K,dp[110][10],s[10][3];
signed main(){
  cin>>H>>W>>K;
  for(int bit=0;bit<(1<<(W-1));bit++){
    bool b=false;
    for(int i=0;i<W-2;i++)
      if((bit>>i)&1&(bit>>(i+1)))b=true;
    if(b)continue;
    for(int i=0;i<W;i++){
      if(i!=0 && ((bit>>(i-1))&1))s[i][0]++;
      else if(i!=W-1 && ((bit>>i)&1))s[i][2]++;
      else s[i][1]++;
    }
  }
  dp[0][0]=1;
  for(int i=0;i<H;i++)
    for(int j=0;j<W;j++)
      for(int k=0;k<3;k++)
        if(0<=j+k-1 && j+k-1<W)dp[i+1][j+k-1]=(dp[i+1][j+k-1]+dp[i][j]*s[j][k]%mod)%mod;
  cout<<dp[H][K-1]<<endl;
}