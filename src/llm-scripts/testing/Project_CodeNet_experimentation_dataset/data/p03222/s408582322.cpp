#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

ll dp[105][10];
ll a[10][10];
const ll MOD=1e9+7;

int main(){
  int h,w,k;
  cin>>h>>w>>k;
  for(int bit=0;bit<1<<w-1;bit++){
    bool ok=true;
    rep(i,w-2){
      if((bit&1<<i)&&(bit&1<<i+1)) ok=false;
    }
    if(!ok) continue;
    rep(i,w){
	if(i==0&&!(bit&1<<i)||i==w-1&&!(bit&1<<i-1)||!(bit&1<<i)&&!(bit&1<<i-1))
	  a[i][i]++;
    if(i==0) continue;
	if(bit&1<<i-1) a[i][i-1]++;
    }
  }
  dp[0][0]=1;
  for(int i=1;i<=h;i++){
    rep(j,w){
      if(j>0) dp[i][j]=(dp[i][j]+dp[i-1][j-1]*a[j][j-1])%MOD;
      dp[i][j]=(dp[i][j]+dp[i-1][j]*a[j][j])%MOD;
      if(j<w-1) dp[i][j]=(dp[i][j]+dp[i-1][j+1]*a[j+1][j])%MOD;
    }
  }
  cout<<dp[h][k-1]<<endl;
  return 0;
}