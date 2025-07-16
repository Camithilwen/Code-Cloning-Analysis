#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int A, B;
  cin >> A >> B;
  int x = 0;
  int C = A;
  
  for (int i = 0; i < B - A + 1; i++) {
    
    int y = C / 10000 + C / 1000 % 10 *10 + C / 100 % 10 * 100 + C / 10 % 10 * 1000 + C % 10 * 10000;
   
     if ( C == y ){
      x += 1;
    }
    
    
    C += 1;
  }
  
  cout << x << endl;
}