// REDO

#include <iostream>

using namespace std;

int main() {
  int N, x;
  cin >> N >> x;

  long long cnt = 0, b = 0, a;
  for (int i = 0; i < N; ++i) {
    cin >> a;
    if (a > x) {
      cnt += a - x;
      a = x;
    }
    if (b + a > x) {
      cnt += b + a - x;
      b = x - b;
    } else {
      b = a;
    }
  }

  cout << cnt << endl;
}
