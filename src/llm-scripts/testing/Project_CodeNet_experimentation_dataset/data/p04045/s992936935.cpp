#include <bits/stdc++.h>
using namespace std;

vector<bool> digit(10, false);

bool check(int N) {
  bool res = true;
  while(N > 0) {
    int x = N % 10;
    
    if (digit[x]) {
      res = false;
      break;
    }
    N /= 10;
  }
  
  return res;
    
}

int main() {
  int N, K;
  cin >> N >> K;
  
  for (int i = 0; i < K; i++) {
    int x;
    cin >> x;
    digit[x] = true;
  }
  
  while(true) {
    if (check(N)) {
      cout << N << endl;
      return 0;
    }
   
    N++;
  }
  
}