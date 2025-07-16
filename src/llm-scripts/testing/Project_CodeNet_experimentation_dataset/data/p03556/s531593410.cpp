#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, x, ans = 0;
  cin >> N;
  
  for (int i = N; i > 0; i--) {
    x = sqrt(i);
    x = x * x;
    if (i == x) {
      ans = i;
      break;
    }
  }
  
  cout << ans << endl;
}