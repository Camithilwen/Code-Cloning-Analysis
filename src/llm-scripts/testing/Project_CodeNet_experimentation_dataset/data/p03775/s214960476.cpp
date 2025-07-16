#include <bits/stdc++.h>
using namespace std;

int main () {
  long long N;
  cin >> N;
  long long M = 1;
  
  for (long long i = 2; i <= sqrt(N); i++) {
    if (N % i == 0){
      M = i;
    }
  }
  
  long long L = max(M,N/M);
  int count = 0;
  for (int i = 0; i < 11; i++) {
    count++;
    if (L / 10 == 0){
      cout << count << endl;
      return 0;
    }
    L /= 10;
  }    
}
   