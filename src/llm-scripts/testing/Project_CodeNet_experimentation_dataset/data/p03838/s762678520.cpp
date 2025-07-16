#include <bits/stdc++.h>
using namespace std;

int main(){
  int x, y;
  cin >> x >> y;
  
  long long ans = 0;
  ans += abs(abs(x) - abs(y));
  if(x > 0){
    if(y > 0 && x > y) ans += 2;
    if(y < 0) ans++;
  }
  if(x < 0){
    if(y < 0 && x > y) ans += 2;
    if(y > 0) ans++;
  }
  if(x == 0 && y < 0) ans++;
  if(y == 0 && x > 0) ans++;
  
  cout << ans << endl;
}