#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  int pow;
  int limit = N;
  
  for (int i = 0; i < N; i++){
    pow = 1;
    
    for (int j = 0; j < i; j++){
      pow *= 2;
    }
    
    if (K < pow){
      limit = i;
      break;
    }
  }
  
  int total = 1;
  
  for (int i = 0; i < limit; i++){
    total *= 2;
  }
  
  for (int i = 0; i < N - limit; i++){
    total += K;
  }
  
  cout << total << endl;
}
