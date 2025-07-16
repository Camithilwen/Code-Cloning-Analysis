#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  int ans;
  cin >> A >> B;
 
  if(B == 1){
      cout << "0" << endl;
      return 0;
  }
  
  ans = ((B-A) + (A-2))/(A-1) + 1;
  cout << ans << endl;
}