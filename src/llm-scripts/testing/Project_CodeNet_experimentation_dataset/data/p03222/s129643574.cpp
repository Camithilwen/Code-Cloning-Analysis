#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  int H,W,K;
  cin>>H>>W>>K;
  ll mod=1e9+7;
  ll dp[H+1][W]={};
  dp[0][0]=1;
  ll L[W]={};
  ll M[W]={};
  ll R[W]={};
  if(W>1) rep(i,(1<<(W-1))){
    int F=1;
    rep(j,W-2) if((i&(1<<j))&&(i&(1<<(j+1)))) F=0;
    if(F) rep(j,W-1){
      if(i&(1<<j)){
        R[j]++;
        L[j+1]++;
      }
    }
    if(F) rep(j,W){
      if(j==0){
        if((i&(1<<j))==0) M[j]++;
      }else if(j==W-1){
        if((i&(1<<(j-1)))==0) M[j]++;
      }else{
        if((i&(1<<(j-1)))==0&&(i&(1<<j))==0) M[j]++;
      }
    }
  }
  rep(i,H){
    rep(j,W){
      if(j==0) dp[i+1][j]=(dp[i][j]*M[j]+dp[i][j+1]*R[j])%mod;
      else if(j==W-1) dp[i+1][j]=(dp[i][j]*M[j]+dp[i][j-1]*L[j])%mod;
      else dp[i+1][j]=(dp[i][j]*M[j]+dp[i][j+1]*R[j]+dp[i][j-1]*L[j])%mod;
    }
  }
  if(W==1) cout<<1<<endl;
  else cout<<dp[H][K-1]<<endl;
}