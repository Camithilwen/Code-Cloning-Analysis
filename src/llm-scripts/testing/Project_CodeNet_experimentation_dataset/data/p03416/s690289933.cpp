#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int res = 0;
  for (int i = A; i <= B; i++) {
    if (i/10000 == i%10) {
      if (i/1000%10 == i%100/10) {
        res += 1;
      }
      i += 9;
    }
  }
  cout << res << endl;
}