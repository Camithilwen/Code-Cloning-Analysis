#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

  int n, a = 0, b = 0, c;
  cin >> a >> b >> c;
  cin >> n;
  cout << (a + b + c) - max(max(a, b), c) + (max(max(a, b), c) << n);
}
