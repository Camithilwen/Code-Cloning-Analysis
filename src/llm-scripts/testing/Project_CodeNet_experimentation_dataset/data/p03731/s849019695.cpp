#include <iostream>
using namespace std;
int main() {
  int T, t, b{-(1<<30)}, ans{};
  cin >> T >> T;
  while (cin >> t) {
    ans += t < b + T ? t - b : T;
    b = t;
  }
  cout << ans << endl;
}
