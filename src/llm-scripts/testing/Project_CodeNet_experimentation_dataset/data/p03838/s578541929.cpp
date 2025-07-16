# include <bits/stdc++.h>
typedef long long lint;
using namespace std;

lint gcd(lint x, lint y) {
  if(x == 0) { return y; }
  else { return gcd(y%x,x); }
}

lint lcm(lint x, lint y) { return x/gcd(x,y)*y; }


int main() {
  lint x,y,ans; cin >> x >> y;

  if(abs(x) == abs(y)) {
    ans = 1;
  } else if(abs(x) < abs(y)) {
    ans = abs(y)-abs(x);
    if(x < 0) { ans++; }
    if(y < 0) { ans++; }
  } else if(abs(x) > abs(y)) {
    ans = abs(x)- abs(y);
    if(x > 0) { ans++; }
    if(y > 0) { ans++; }
  }

  cout << ans << endl;
  return 0;
}