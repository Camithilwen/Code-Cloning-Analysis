#include <iostream>

using namespace std;

int main() {
  int a;
  cin >> a;
  int res = 0;
  for (int i = 0; i < 3; ++i) res = (res + 1) * a;
  cout << res << endl;
}
