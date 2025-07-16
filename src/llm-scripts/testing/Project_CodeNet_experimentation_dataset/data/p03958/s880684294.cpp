#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  int K, a, M{};
  cin >> K >> a;
  while (cin >> a) M = max(M, a);
  cout << max(0, 2 * M - K - 1) << endl;
}
