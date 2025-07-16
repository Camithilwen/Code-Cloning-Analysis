#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a; 
  
  cin >> a;
  int x = a;
  int z = std::pow(x, 2);
  int y = std::pow(x, 3);
  int ans = x+y+z;
  cout << ans << endl;
  return 0;
 }