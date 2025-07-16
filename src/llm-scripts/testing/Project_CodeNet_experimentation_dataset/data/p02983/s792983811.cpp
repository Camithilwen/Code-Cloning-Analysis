#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
using namespace std;

#define MOD 2019

int main(){
  long long int L = 0,R = 0;
  cin >> L >> R;
  if(L + MOD <= R){
    cout << 0 << endl;
  }else{
  L = L % MOD;
  R = R % MOD;
  int answer = 100000000;
  for(int i = L;i < R;i++){
    for(int j = i + 1;j <= R;j++){
      answer = min(answer,((i*j)%2019));
    }
  }
  cout << answer << endl;
}
}
