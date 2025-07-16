#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, M = 0, h = 0;
  cin >> N;
  M = N;
    
  for(int i = 0; i < 10; i++) {
    h += M % 10;
    M = M / 10;
    if(M == 0) {
      break;
    }
  }

  if(N % h == 0) {
  	cout << "Yes" << endl; 
  }
  
  else {
    cout << "No" << endl;
  }
  
}