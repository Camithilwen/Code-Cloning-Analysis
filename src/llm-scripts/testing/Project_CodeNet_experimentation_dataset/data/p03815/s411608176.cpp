#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t x;
  cin >> x;
  
  int64_t a = x/11*2;

  if(x%11 == 0){
    cout << a << endl;
  }
  else if(x%11 <= 6){
    cout << a+1 << endl;
  }
  else{
    cout << a+2 << endl;
  }
 
}
             
 