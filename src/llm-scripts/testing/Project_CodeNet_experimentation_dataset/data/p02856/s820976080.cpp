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

int main(){

  // read problem
  long long int M, tmp1, tmp2;
  std::vector<long long int> d, c;

  scanf("%lld", &M);

  for(long long int i = 0; i < M; i++){
    scanf("%lld%lld", &tmp1, &tmp2);
    d.push_back(tmp1);
    c.push_back(tmp2);
  }

  /*std::cerr << "M: " << M << std::endl;
  std::cerr << "d: " << std::endl;
  for(long long int i = 0; i < M; i++){
    std::cerr << d[i] << " ";
  }std::cerr << std::endl;
  std::cerr << "c: " << std::endl;
  for(long long int i = 0; i < M; i++){
    std::cerr << c[i] << " ";
  }std::cerr << std::endl;*/

  // solve problem
  long long int carryover = 0;
  long long int topdigit, period, tmp_pos;
  long long int ans = 0;
  std::vector<long long int> tmp_digits(10);

  for(long long int i = 0; i < M; i++){
    //std::cerr << "i: " << i << " carryover: " << carryover << std::endl;
    // calculate carryover
    topdigit = d[i];
    while(carryover>0){
      ans++;
      topdigit = topdigit+carryover;
      carryover = topdigit/10;
      topdigit = (topdigit+10)%10;
    }

    //std::cerr << "carryover is done" << std::endl;

    // calculate one period
    tmp_digits[0] = topdigit;
    for(long long int j = 1; j < 10; j++){
      tmp_digits[j] = d[i];
    }
    tmp_pos = 0;
    period = 0;
    for(long long int tmp_pos = 0; tmp_pos < 9; tmp_pos++){
      while(tmp_digits[tmp_pos] > 0){
        period++;
        tmp_digits[tmp_pos+1] = tmp_digits[tmp_pos] + tmp_digits[tmp_pos+1];
        tmp_digits[tmp_pos] = tmp_digits[tmp_pos+1]/10;
        tmp_digits[tmp_pos+1] = (tmp_digits[tmp_pos+1]+10)%10;
      }
      /*for(long long int k = 0; k < 10; k++){
        std::cerr << tmp_digits[k];
      }std::cerr << std::endl;*/
    }

    ans += period*((c[i]-1)/9);
    //std::cerr << "one period calculated" << std::endl;

    // calculate amari
    tmp_pos = 9 - ((c[i]+8)%9);
    if(tmp_pos == 0){
      continue;
    }
    tmp_digits[tmp_pos] = topdigit;
    for(long long int j = tmp_pos+1; j < 10; j++){
      tmp_digits[j] = d[i];
    }
    for(long long int tmp_pos = 0; tmp_pos < 9; tmp_pos++){
      while(tmp_digits[tmp_pos] > 0){
        ans++;
        tmp_digits[tmp_pos+1] = tmp_digits[tmp_pos] + tmp_digits[tmp_pos+1];
        tmp_digits[tmp_pos] = tmp_digits[tmp_pos+1]/10;
        tmp_digits[tmp_pos+1] = (tmp_digits[tmp_pos+1]+10)%10;
      }
    }

    //std::cerr << "amari calculated" << std::endl;

    carryover = tmp_digits[9];
  }

  std::cerr << "Answer: " << std::endl;
  std::cout << ans << std::endl;

  return 0;
}
