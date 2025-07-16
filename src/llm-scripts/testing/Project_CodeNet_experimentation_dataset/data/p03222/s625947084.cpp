// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
#define MOD 1000000007
#define MAX_H 110
#define MAX_W 10
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
ll h,w,k,fr;
ll dp[MAX_H][MAX_W]={};
ll pat_dp[MAX_W][2];
ll pat[MAX_W];
signed main(){
  ll st,le,ri;
  init_io();
  cin >> h >> w >> k;
  if(w==1){
    cout << 1<<endl;
    return 0;
  }
  dp[0][0] = 1;
  pat_dp[0][0] = 0;
  pat_dp[0][1] = 0;
  pat[0] = 1;

  pat_dp[1][0] = 1;
  pat_dp[1][1] = 0;
  pat[1] = 1;

  for(int i=2;i<MAX_W;i++){
    pat_dp[i][0] = pat_dp[i-1][0]+pat_dp[i-1][1];
    pat_dp[i][1] = pat_dp[i-1][0];

    pat_dp[i][0] %= MOD;
    pat_dp[i][1] %= MOD;

    pat[i] = (pat_dp[i][0]+pat_dp[i][1])%MOD;
  }
  for(int i=1;i<=h;i++){
    for(int j=0;j<w;j++){
      st = dp[i-1][j];
      st *= (pat[j]*pat[w-1-j])%MOD;
      st %= MOD;

      le = 0;
      ri = 0;

      if(j!=0){
        le = (dp[i-1][j-1]*(pat[j-1]*pat[w-1-j])%MOD)%MOD;
      }
      if(j!=w-1){
        ri = (dp[i-1][j+1]*(pat[j]*pat[w-2-j]))%MOD;
      }
      dp[i][j] = (st+ri+le)%MOD;
    }
  }
  cout << dp[h][k-1]<<endl;
}
