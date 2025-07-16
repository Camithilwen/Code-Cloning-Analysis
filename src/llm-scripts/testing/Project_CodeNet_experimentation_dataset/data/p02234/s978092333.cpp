#include <stdio.h>

#define MAX_N 100
#define INF 1e8

int main(){
  int N,i,j,k,l,q,r[MAX_N],c[MAX_N],p[MAX_N+1];
  int dp[MAX_N+1][MAX_N+1];
  scanf("%d",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d%d",&r[i],&c[i]);
  }
  p[0] = r[0];
  for(i = 1 ; i <= N ; i++){
    p[i] = c[i-1];
  }
  N++;
  for(i = 0 ; i < N ; i++){
    dp[i][i] = 0;
  }
  for(l = 2 ; l < N ; l++){
    for(i = 1 ; i < N-l+1 ; i++){
      j = i + l - 1;
      dp[i][j] = INF;
      for(k = i ; k <= j-1 ; k++){
        q = dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j];
        if(q < dp[i][j]){
          dp[i][j] = q;
        }
      }
    }
  }
  printf("%d\n",dp[1][N-1]);
  return 0;
}