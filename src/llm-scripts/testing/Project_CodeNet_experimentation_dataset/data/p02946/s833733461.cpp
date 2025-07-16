#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int K,X;
  cin >> K >> X;
  
  for (int i = 0; i < K*2-1; i++) {
    if (i == K*2-2){
      cout << X - K + 1 + i << endl;
    }
    else {
      cout << X - K + 1 + i << ' ';
    } 
  }
}
  