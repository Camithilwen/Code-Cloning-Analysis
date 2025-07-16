#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, K;
  cin >> N >> K;
  
  int x = 1;
  
  for (int i = 0; i < N; i++) { // iのスコープはforの終わりまで

    if( x * 2 <= x + K ){
      x *= 2;
      
    }
    
    else {
      x += K;
      
    }
  }
  
  cout << x <<endl;
}