#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

long long int MOD = 1e9 + 7;

int main(){

  // read problem
  long long int N;
  std::string Stmp;
  scanf("%lld", &N);
  std::cin >> Stmp;
  std::string S = "W" + Stmp;

  std::cerr << "S: " << std::endl << S << std::endl;

  // solve problem
  long long int tmp_left = 0;
  long long int tmp_state = 0; // left
  long long int ans = 1;
  long long int possible = 1;

  for(long long int i = 1; i <= 2*N; i++){
    std::cerr << i << " " << tmp_left << " " << tmp_state << std::endl;
    if(S[i] != S[i-1]){
      // keep tmp_state
      if(tmp_state == 0){ // left
        tmp_left++;
      }
      else{// right
        ans *= tmp_left;
        ans = (ans+MOD)%MOD;
        tmp_left--;
      }
    }
    else{
      // change tmp_state
      if(tmp_state == 0){
        tmp_state = 1; // right
        ans *= tmp_left;
        ans = (ans+MOD)%MOD;
        tmp_left--;
      }
      else{
        tmp_state = 0; // left
        tmp_left++;
      }
    }
    // check answer
    if(tmp_left < 0){
      ans = 0;
      break;
    }
  }

  // left has not been used up
  if(tmp_left != 0){
    ans = 0;
  }

  // order of choosing pairs
  for(long long int i = 1; i <= N; i++){
    ans *= i;
    ans = (ans+MOD)%MOD;
  }

  std::cerr << "Answer: " << std::endl;
  std::cout << ans << std::endl;

  return 0;
}