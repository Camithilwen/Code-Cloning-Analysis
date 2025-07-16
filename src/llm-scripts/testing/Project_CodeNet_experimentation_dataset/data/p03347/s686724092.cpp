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

int people[100005][4];
int sum[100005];

int main(){
  int N;
  scanf("%d", &N);
  std::vector<int > A(N);
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  int prev=0;
  long long ans=0;
  if (A[0]!=0){
    std::cout << "-1" << std::endl;
    return 0;
  }
  for (int i=1; i<N; i++){
    if (A[i]>prev+1) {
      std::cout << "-1" << std::endl;
      return 0;
    } else if (A[i]==prev+1){
      ans++;
    } else {
      ans+=A[i];
    }
    prev = A[i];
  }
  std::cout << ans <<std::endl;
  return 0;
}