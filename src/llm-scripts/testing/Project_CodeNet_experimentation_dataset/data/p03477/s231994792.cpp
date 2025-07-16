#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;

  string ans;
  int L = A + B, R = C + D;
  if (L > R) {
    ans = "Left";
  } else if (L == R) {
    ans = "Balanced";
  } else {
    ans = "Right";
  }
  cout << ans << endl;
  return 0;
}