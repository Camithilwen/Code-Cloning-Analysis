#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  if(n == 0){
      cout << 0 << '\n';
      return 0;
  }
  int base = -2;
  string ans;
  while(n){
    int r = n%base;
    n = n/base;
    if(r < 0) n++;
    if(r < 0) r = r*(-1);
    char x = r + '0';
    ans = x + ans;
    
  }
  cout << ans << '\n';
}