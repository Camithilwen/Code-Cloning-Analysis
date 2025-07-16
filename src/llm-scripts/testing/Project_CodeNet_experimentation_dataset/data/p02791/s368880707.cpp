#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;

  int res = 0;
  int mn = 200001;
  for (int n = 0; n < N; ++n) {
    int A;
    cin >> A;
    if (A < mn) {
      ++res;
      mn = A;
    }
  }
  cout << res << endl;

  return 0;
}
