#include <bits/stdc++.h>
using namespace std;

int main() {
  int r;cin>>r;
  string ans;
  if (r >= 2800) ans = "AGC";
  else if (r >= 1200) ans = "ARC";
  else ans = "ABC";
  cout << ans << endl;
  return 0;
}
