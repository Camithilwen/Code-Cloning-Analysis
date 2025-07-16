#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


bitset<13000> dp[85][85];
int A[85][85];
int B[85][85];

int main(){
  int H, W;
  cin >> H >> W;
  int ret = 0;
  rep(i,H){
    rep(j,W){
      cin >> A[i][j];
      ret += A[i][j];
    }
  }
  rep(i,H){
    rep(j,W){
      cin >> B[i][j];
    }
  }
  
  dp[0][0][abs(A[0][0]-B[0][0])+6500] = true;
  dp[0][0][abs(B[0][0]-A[0][0])+6500] = true;

  rep(i,H){
    rep(j,W){
      if(i+1<H){
        dp[i+1][j] |= (dp[i][j] << abs(A[i+1][j]-B[i+1][j]));
        dp[i+1][j] |= (dp[i][j] >> abs(A[i+1][j]-B[i+1][j]));
      }
      if(j+1<W){
        dp[i][j+1] |= (dp[i][j] << abs(A[i][j+1]-B[i][j+1]));
        dp[i][j+1] |= (dp[i][j] >> abs(A[i][j+1]-B[i][j+1]));
      }
    }
  }
  
  rep(i,13000){
    if(dp[H-1][W-1][i]){
      ret = min(ret, abs(i-6500));
    }
  }

  cout << ret << endl;
  
  return 0;
}


