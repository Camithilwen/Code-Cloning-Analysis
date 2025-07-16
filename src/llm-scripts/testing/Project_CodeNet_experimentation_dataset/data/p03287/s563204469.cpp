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


int main(){
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  std::vector<int > A(N);
  for (int i=0; i<N; i++){
    scanf("%d", &A[i]);
  }
  int sum=0;
  std::map<int, int> mp;
  mp[0]++;
  long long ans = 0;
  for (int i=0; i<N; i++){
    sum+=A[i];
    sum %= M;
    ans += mp[sum];
    mp[sum]++;
  }
  std::cout << ans << std::endl;
  return 0;
}
 