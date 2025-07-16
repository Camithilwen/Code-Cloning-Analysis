#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <tuple>
#include <bitset>
#include <random>

int money[300];

int main(){
  int x, y;
  std::cin >> x >> y;
  int ans = 0;
  money[1]=300000;
  money[2]=200000;
  money[3]=100000;
  ans += money[x];
  ans += money[y];
  if (x==y && x==1){
    ans += 400000;
  }
  std::cout << ans << std::endl;
  return 0;
}