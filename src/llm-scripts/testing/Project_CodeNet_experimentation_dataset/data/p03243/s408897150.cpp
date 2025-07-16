#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int x = 100;
  int f = n/x;
  int q = n%10;
  n /= 10;
  int y = n%10;
  if(y > f)cout << f + 1 << f + 1 << f + 1 << '\n';
  else if(y == f && q > f) cout << f + 1 << f + 1 << f + 1 << '\n';
  else cout << f << f << f << '\n';
}