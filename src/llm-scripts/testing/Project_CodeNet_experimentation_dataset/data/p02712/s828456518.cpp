#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int FB, F, B;
  FB = N / 15;
  F = N / 3;
  B = N / 5;
  
  long long ans = 0;
  
  for(int i = 1; i <= N; i++) {
    ans += i;
  }
  
  for(int i =1 ; i <= F; i++) {
    ans -= i*3;
  }
  
  for(int i =1 ; i <= B; i++) {
    ans -= i*5;
  }
  
  for(int i =1 ; i <= FB; i++) {
    ans += i*15;
  }  
  
  cout << ans << endl;
}