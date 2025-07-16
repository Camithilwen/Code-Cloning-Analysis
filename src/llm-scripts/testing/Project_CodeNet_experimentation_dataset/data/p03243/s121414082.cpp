#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 111;
  for (int i = 1; i < 10; i++) {
    if (N <= ans * i) {
      cout << ans * i << endl;
      break;
    }
    else if (i == 9) {
      cout << 1111 << endl;
    }
  }
}