#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define MOD 1000000007

int main()
{
  int h,w,k;cin>>h>>w>>k;
  vector<vector<ll>> dp(h+1,vector<ll>(w,0));
  dp[0][0]=1;
  int i,j,l;
  for(i=1;i<=h;i++)
  {
    for(j=0;j<(1<<(w-1));j++)
    {
      bool warp=false;
      for(l=0;l<w-2;l++)
      {
        if((j&(1<<l))&&(j&(1<<(l+1))))warp=true;
      }
      if(warp)continue;
      for(l=0;l<w;l++)
      {
        bool con=false;
        if(l>0&&(j&(1<<(l-1))))
        {
          dp[i][l]+=dp[i-1][l-1];
          dp[i][l]%=MOD;
          con=true;
        }
        if(l<w-1&&(j&(1<<l)))
        {
          dp[i][l]+=dp[i-1][l+1];
          dp[i][l]%=MOD;
          con=true;
        }
        if(!con)
        {
          dp[i][l]+=dp[i-1][l];
          dp[i][l]%=MOD;
        }
      }
    }
  }
  cout<<dp[h][k-1]<<endl;
}
