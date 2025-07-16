#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  string S;
  cin >> S;
  int count = 0;
  rep(i,3){
    if(S.at(i) == 'R'){
      count ++;
    }
  }
  if(count == 2){
    if(S.at(1) == 'S'){
      count --;
    }
  }
  cout << count << endl;
  return 0;
}