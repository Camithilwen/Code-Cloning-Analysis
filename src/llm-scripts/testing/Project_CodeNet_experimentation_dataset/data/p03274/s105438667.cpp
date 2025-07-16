#include <bits/stdc++.h>
using namespace std;

void chmin(int& a, int b) {
  if (a > b) a = b;
}

int main() {
  int N, K;
  cin >> N >> K;
  
  vector<int> minus, plus;
  
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (x >= 0) {
      plus.push_back(x);
    } else {
      minus.push_back(-x);
    }
  } 
  
  sort(minus.begin(), minus.end());
  
  int ans = 300000000;
  
  int M = minus.size(), P = plus.size();
  // minusの個数, Kとのminを
  int minus_num = min(M, K);
  int plus_num = min(P, K);
  
  if (minus_num == 0) {
    ans = plus[K-1];
  } else if (plus_num == 0) {
    ans = minus[K-1];
  } else {
    for (int i = K - plus_num; i <= minus_num; i++) {
      chmin(ans, min(minus[i-1], plus[K-i-1]) + minus[i-1] + plus[K-i-1]);
    }
  }
  cout << ans << endl;
  

}