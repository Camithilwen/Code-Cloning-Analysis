#include <bits/stdc++.h>
using namespace std;
  
int main() {
  int N;
  cin >> N;
  
  vector<int>A(N);
  vector<int>B(N,0);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (i >= N/2){
      B.at(i) = A.at(i);
    }
  }
  
  for (int i = N/2; i > 0; i--) {
    int judge = 0;
    for (int j = 1; j <= N/i; j++) {
      if (B.at(i*j-1) == 1){
        judge++;
      }
    }
    if (judge % 2 != A.at(i-1)){
      B.at(i-1) = 1;
    }
  }
  
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (B.at(i) == 1){
      count++;
    }
  }
  cout << count << endl;
  for (int i = 0; i < N; i++) {
    if (B.at(i) == 1){
      cout << i+1;
      count--;
      if (count != 0){
        cout << ' ';
      }
    }
  }
  cout << endl;
}
      
    
      
  
  
  
 