#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <queue>
using namespace std;

#define N 303

int dp[N][N][N];

char s[N];
void solve() {
  scanf(" %s",s+1);
  int n = strlen(s+1);
  int k;scanf("%d",&k);
  for(int cc = k;cc>=0;--cc) {
    for(int i=1;i<=n;++i) {
      for(int j=n;j>=i+1;--j) {
        dp[cc][i+1][j] = max(dp[cc][i+1][j], dp[cc][i][j]);
        dp[cc][i][j-1] = max(dp[cc][i][j-1],dp[cc][i][j]);
        if(s[i]==s[j]) {
          dp[cc][i+1][j-1] = max(dp[cc][i+1][j-1], dp[cc][i][j]+1);
        } else if(cc>0){
          dp[cc-1][i+1][j-1] = max(dp[cc-1][i+1][j-1], dp[cc][i][j]+1);
        }
      }
    }
  }
  int ret = 0;
  for(int i=1;i<=n;++i) {
    for(int cc=0;cc<=k;++cc) {
      ret = max(ret, dp[cc][i][i-1]*2);
      ret = max(ret, dp[cc][i+1][i]*2);
      ret = max(ret,1 + dp[cc][i][i]*2);
    }
  }
  printf("%d\n", ret);
}

int main() {
  //freopen("input.txt","r",stdin);
  solve();
  return 0;
}
