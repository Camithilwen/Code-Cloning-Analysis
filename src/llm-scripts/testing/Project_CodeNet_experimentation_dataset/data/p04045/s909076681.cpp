#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int n, k;
  cin >> n >> k;

  bool digits[10] = {false};

  for (int i = 0; i < k; ++i) {
    int x; cin >> x;
    digits[x] = true;
  }

  while (n <= INT_MAX) {
    int tmp = n;

    while (tmp) {
      int d = tmp % 10;
      if (digits[d]) break;
      else tmp /= 10;
    }

    if (tmp == 0) break;
    else n++;
  }

  cout << n << "\n";
}
