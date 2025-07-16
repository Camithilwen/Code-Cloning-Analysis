#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <utility>

int dp1[3004][3004];
int dp2[3004][3004];

int main(){
  int N, T;
  scanf("%d", &N);
  scanf("%d", &T);
  std::vector<int > A(N), B(N);
  int max=-1;
  int maxindex=-1;
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
    scanf("%d", &B[i]);
  }
  for (int i=0; i<3004; i++){
    for (int j=0; j<3004; j++){
      dp1[i][j]=-1;
      dp2[i][j]=-1;
    }
  }
  dp1[0][0]=0;
  dp2[N][0]=0;
  for (int i=0; i<N; i++){
    //printf("i1=%d\n", i);
    for (int j=0; j<=T; j++){
      if (j>0) dp1[i+1][j]=std::max(dp1[i+1][j-1], dp1[i+1][j]);
      if (dp1[i][j]!=-1){
	if (j+A[i]<=T) dp1[i+1][j+A[i]]=std::max(dp1[i+1][j+A[i]], dp1[i][j]+B[i]);
	dp1[i+1][j] = std::max(dp1[i+1][j], dp1[i][j]);
      }
    }
  }
  for (int i=N-1; i>=0; i--){
    //printf("i2=%d\n", i);
    for (int j=0; j<=T; j++){
      if (j>0) dp2[i+1][j]=std::max(dp2[i+1][j-1], dp2[i+1][j]);
      if (dp1[i+1][j]!=-1){
	if (j+A[i]<=T) dp2[i][j+A[i]]=std::max(dp2[i][j+A[i]], dp2[i+1][j]+B[i]);
	dp2[i][j] = std::max(dp2[i][j], dp2[i+1][j]);
      }
    }
  }
  int ans = -1;
  for (int k=0; k<N; k++){
    //printf("k=%d\n", k);
    int cand = -1;
    for (int j=1; j<T-1; j++){
      int val1 = std::max(dp1[k][j], 0);
      int val2 = std::max(dp2[k+1][T-j-1], 0);
      cand = std::max(cand, val1+val2);
      //if (val1+val2+B[k]>55) printf("k=%d, j=%d, %d + %d + B[%d](=%d)\n", k, j, dp1[k][j], dp2[k+1][T-j],k, B[k]);
    }
    ans = std::max(ans, cand+B[k]);
  }
  std::cout << ans << std::endl;
  return 0;
}
 