#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N;
  
  string S; cin >> S;
  
  int sumE = 0, sumW = 0, ans = N, leftE = 0, leftW = 0;
  
  for (int i = 0; i < N; i++) {
    
    if (S.at(i) == 'E') sumE++;
    if (S.at(i) == 'W') sumW++;
    
  }
  
  for (int i = 0; i < N; i++) {
    
    int tmp = 0;
    
    if (S.at(i) == 'E') tmp = 1;
    if (S.at(i) == 'W') tmp = 0;
    
    int cost = leftW + sumE - leftE - tmp;
    
    ans = min(ans, cost);
    
    if (S.at(i) == 'E') leftE++;
    if (S.at(i) == 'W') leftW++;
    
  }
  
  cout << ans << endl;
  
}