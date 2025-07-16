#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

ld dp[305][305][305];

int main() {
  ll n;
  cin>>n;
  ll a[n],x=0,y=0,z=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]==1) x++;
    else if(a[i]==2) y++;
    else z++;
  }
  for(int k=0;k<=n;k++)
    for(int j=0;j<=n;j++)
      for(int i=0;i<=n;i++)
          dp[i][j][k]=0.0;
  ll i=0,j=0,k=0;
  ld val=0;
 // cout<<x<<" "<<y<<" "<<z<<"\n";
  for( k=0;k<=n;k++){
    for( j=0;j<=n;j++){
      for( i=0;i<=n;i++){
        //cout<<i<<" "<<j<<" "<<k<<"\n";
        if(i+j+k>n) continue;
        if(i+j+k==0) continue;
        else{
          dp[i][j][k]=n/(long double)(i+j+k);
          if(i>0) dp[i][j][k]+=(dp[i-1][j][k]*i)/(long double)(i+j+k);
          if(j>0) dp[i][j][k]+=(dp[i+1][j-1][k]*j)/(long double)(i+j+k);
          if(k>0) dp[i][j][k]+=(dp[i][j+1][k-1]*k)/(long double)(i+j+k);
        }
       // cout<<i<<" "<<j<<" "<<k<<"-->"<<dp[i][j][k]<<"\n";
      }
    }
  }
  cout<<fixed<<setprecision(10);
  cout<<dp[x][y][z]<<"\n";
}