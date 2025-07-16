#include <bits/stdc++.h>
using namespace std;
 
int main() {

  int N, K;
  cin >> N >> K;
  int x = 1;
  
  for (int i = 0;N > i;i++){
    
    cin >> x;
    
    if (x < K){
      x *= 2;
    }
    else{
      x += K;
    }
  }
  cout << x << endl;
}