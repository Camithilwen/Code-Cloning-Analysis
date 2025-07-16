#include <bits/stdc++.h>
using namespace std;
int main() {
  int A,B,ans=0; cin >> A >> B;
  if(A>B) ans += 2*A -1;
  else if(A<B) ans += 2*B -1;
  else if(A==B) ans += 2*A;
  
  cout << ans << endl;
}