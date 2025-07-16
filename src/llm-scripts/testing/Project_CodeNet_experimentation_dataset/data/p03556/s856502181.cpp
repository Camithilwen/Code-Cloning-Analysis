#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
  Int N;
  cin >> N;
  Int ans = 0;
  for (Int i = 1; i * i <= N; i++) {
    ans = i * i;
  }
  
  cout << ans << endl;

}