#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  int64_t minimum;
  for(int i = 0; i < 5; i++) {
    if(i == 0) {
      cin >> minimum;
    }
    else {
      int64_t a;
      cin >> a;
      minimum = min(minimum, a);
    }
  }
  cout << (N - 1) / minimum + 5 << endl;
}